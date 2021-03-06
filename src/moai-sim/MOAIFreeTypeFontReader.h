// Copyright (c) 2010-2017 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIFREETYPEFONTREADER_H
#define	MOAIFREETYPEFONTREADER_H

#if MOAI_WITH_FREETYPE

#include <contrib/moai_utf8.h>

#include <moai-sim/MOAIFontReader.h>

typedef int* MOAIFtLibrary;
typedef int* MOAIFtFace;

//================================================================//
// MOAIFreeTypeFontReader
//================================================================//
/**	@lua	MOAIFreeTypeFontReader
	@text	Implementation of MOAIFontReader that based on FreeType 2.
			Can load and render TTF and OTF font files.
*/
class MOAIFreeTypeFontReader :
	public MOAIFontReader {
private:

	u32				mGlyphCode;
	float			mFaceSize;

	MOAIFtLibrary	mLibrary;
	MOAIFtFace		mFace;
	float			mFaceHeight;

	bool			mAntiAlias;
	ZLColorVec		mPenColor;

	//----------------------------------------------------------------//
	static int		_enableAntiAliasing			( lua_State* L );
	static int		_extractSystemFont			( lua_State* L );
	static int		_setPenColor				( lua_State* L );
	static int		_strokeGlyph				( lua_State* L );

	//----------------------------------------------------------------//
	static void		ExtractSystemFont			( cc8* fontName, ZLStream& stream );

public:
	
	DECL_LUA_FACTORY ( MOAIFreeTypeFontReader )

	//----------------------------------------------------------------//
	int				CloseFontFile				();
	int				GetFaceMetrics				( MOAIFontFaceMetrics& faceMetrics );
	int				GetGlyphMetrics				( MOAIGlyphMetrics& glyphMetrics );
	int				GetKernVec					( u32 c, MOAIKernVec& kernVec );
	bool			HasKerning					();
					MOAIFreeTypeFontReader		();
					~MOAIFreeTypeFontReader		();
	int				OpenFontFile				( cc8* filename );
	void			RegisterLuaClass			( MOAILuaState& state );
	void			RegisterLuaFuncs			( MOAILuaState& state );
	int				RenderGlyph					( MOAIImage& image, float x, float y, const ZLColorBlendFunc& blendFunc );
	int				SelectFace					( float size );
	int				SelectGlyph					( u32 c );
	void			SerializeIn					( MOAILuaState& state, MOAIDeserializer& serializer );
	void			SerializeOut				( MOAILuaState& state, MOAISerializer& serializer );
	int				StrokeGlyph					( MOAIImage& image, float x, float y, float strokeSize, const ZLColorBlendFunc& blendFunc );
};

#endif
#endif
