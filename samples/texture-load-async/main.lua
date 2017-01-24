----------------------------------------------------------------
-- Copyright (c) 2010-2017 Zipline Games, Inc. 
-- All Rights Reserved. 
-- http://getmoai.com
----------------------------------------------------------------

MOAISim.openWindow ( 'test', 320, 480 )

ioThread = MOAITaskQueue.new ()

viewport = MOAIViewport.new ()
viewport:setSize ( 320, 480 )
viewport:setScale ( 320, -480 )

layer = MOAILayer.new ()
layer:setViewport ( viewport )
layer:pushRenderPass ()

texture = MOAITexture.new ()

gfxQuad = MOAIGfxQuad2D.new ()
gfxQuad:setTexture ( texture )
gfxQuad:setRect ( -128, -128, 128, 128 )
gfxQuad:setUVRect ( 0, 0, 1, 1 )

prop = MOAIProp2D.new ()
prop:setDeck ( gfxQuad )
layer:insertProp ( prop )

data = MOAIDataBuffer.new ()
data:loadAsync ( 'moai.png', ioThread, function () texture:load ( data ) data:clear () end )
