RADIANS_PER_DEGREE = 0.01745329

scene = Scene(Scene.SCENE_3D)

ground = ScenePrimitive(ScenePrimitive.TYPE_PLANE, 5, 5)
ground:setColor(0, 1, .5, 1)
scene:addEntity(ground)

box = ScenePrimitive(ScenePrimitive.TYPE_BOX, 1,1,1)
box:setColor(1,.5,0,1)
box:setPosition(0, .5, 0)
scene:addEntity(ground)

camera = scene:getDefaultCamera()
camera.private = {}
camera.private.upVector = Vector3(0,1,0)
camera.private.jaw = 0
camera.private.pitch = 0
camera.private.distance = 15 

camera:setPosition(7,7,7)
camera:lookAt(Vector3(0,0,0), camera.private.upVector)

function onKeyDown(key)
  if key == KEY_LEFT then
  elseif key == KEY_RIGHT then
  elseif key == KEY_UP then
  elseif key == KEY_DOWN then
  end
end

function Update(elapsed)
  local rotation = Quaternion(camera.private.jaw, camera.private.upVector.x, camera.private.upVector.y, camera.private.upVector.z)
  local cameraPosition = Vector3(0, 0, 0);
  cameraPosition.y = cameraPosition.y - camera.private.distance;
  forward = Vector3(cameraPosition.x, cameraPosition.y, cameraPosition.z);
  if (forward:length() < 1) then 
    forward.set(1, 0, 0);
  end 


  camera:setPosition(7,7,7)
  camera:lookAt(Vector3(0,0,0), camera.private.upVector)
end

