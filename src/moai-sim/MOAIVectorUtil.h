// Copyright (c) 2010-2017 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIVECTORUTIL_H
#define	MOAIVECTORUTIL_H

#include <moai-sim/MOAIVectorStyle.h>

class MOAIIndexBuffer;
class MOAIVectorShape;
class MOAIVertexBuffer;
class MOAIVertexFormat;

struct TESStesselator;
typedef float TESSreal;

//================================================================//
// SafeTesselator
//================================================================//
class SafeTesselator {
public:

	static const ZLVec3D	sNormal;

	struct TESStesselator*	mTess;

	//----------------------------------------------------------------//
	void			AddContour				( int numComponents, const void* vertices, int stride, size_t numVertices );
	void			AddPolygon				( const ZLPolygon2D& poly );
	u32				GetTriangles			( MOAIVertexFormat& format, ZLStream& vtxStream, ZLStream& idxStream );
	u32				GetTriangles			( MOAIVertexFormat& format, MOAIVertexBuffer& vtxBuffer, MOAIIndexBuffer& idxBuffer, u32 idxSizeInBytes );
	void			Reset					();
					SafeTesselator			();
					~SafeTesselator			();
	int				Tesselate				( int windingRule, int elementType, int polySize, int vertexSize, const TESSreal* normal = 0 );
};

//================================================================//
// MOAIVectorLineJoin
//================================================================//
class MOAIVectorLineJoin {
public:

		ZLVec2D		mVertex;		// the join vertex
		ZLVec2D		mEdgeVec;		// vector of the next edge
		ZLVec2D		mEdgeNorm;		// normal of preceding edge
		ZLVec2D		mJointNorm;		// avg normal (same as N0 or N1 if path not closed)
		bool		mIsCap;
};

//================================================================//
// MOAIVectorUtil
//================================================================//
class MOAIVectorUtil {
private:

	//----------------------------------------------------------------//
	static int		StrokeWedge				( const MOAIVectorStyle& style, ZLVec2D*& verts, const ZLVec2D& origin, const ZLVec2D& n0, const ZLVec2D& n1, float width );
	
public:
	
	//----------------------------------------------------------------//
	static void		ComputeLineJoins		( MOAIVectorLineJoin* joins, const ZLVec2D* verts, int nVerts, bool open, bool forward, bool interior );
	static u32		GetTriangles			( ZLStream& vtxStream, MOAIVertexBuffer& vtxBuffer, ZLStream& idxStream, MOAIIndexBuffer& idxBuffer, u32 idxSizeInBytes );
	static int		StrokeLine				( const MOAIVectorStyle& style, ZLVec2D* verts, const MOAIVectorLineJoin* joins, int nJoins, float width, bool exact );
};

#endif
