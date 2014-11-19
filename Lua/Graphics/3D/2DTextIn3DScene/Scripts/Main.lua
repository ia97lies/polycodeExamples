
scene = Scene(Scene.SCENE_3D)

ground = ScenePrimitive(ScenePrimitive.TYPE_PLANE, 5, 5)
ground:setColor(0, 1, .5, 1)
scene:addEntity(ground)

box = ScenePrimitive(ScenePrimitive.TYPE_BOX, 1,1,1)
box:setColor(1,.5,0,1)
box:setPosition(0, .5, 0)
scene:addEntity(box)

camera = scene:getDefaultCamera()

function Update(elapsed)
  camera:setPosition(7,7,7)
  camera:lookAt(Vector3(0,0,0), Vector3(0,1,0))
  scene2D = Scene(Scene.SCENE_2D)
  scene2D:getActiveCamera():setOrthoSize(640, 480)
  label = SceneLabel("Hello, Polycode!", 20, 2, 2)
  scene2D:addChild(label)

end
