RADIANS_PER_DEGREE = 0.01745329

scene = Scene(Scene.SCENE_3D)

ground = ScenePrimitive(ScenePrimitive.TYPE_PLANE, 5, 5)
ground:setColor(0, 1, .5, 1)
scene:addEntity(ground)

box = ScenePrimitive(ScenePrimitive.TYPE_BOX, 1,1,1)
box:setColor(1,.5,0,1)
box:setPosition(0, .5, 0)
scene:addEntity(box)

camera = scene:getDefaultCamera()
camera.private = {}
camera.private.upVector = Vector3(0,1,0)
camera.private.yaw = 5
camera.private.pitch = 5 
camera.private.distance = 15 

camera:setPosition(7,7,7)
camera:lookAt(Vector3(0,0,0), camera.private.upVector)

function checkBoundary(angle) 
  if angle < 0 then angle = angle + 360 end
  if angle >= 360 then angle = angle - 360 end
  return angle
end

function onKeyDown(key)
  if key == KEY_LEFT then
    camera.private.yaw = checkBoundary(camera.private.yaw + 5)
  elseif key == KEY_RIGHT then
    camera.private.yaw = checkBoundary(camera.private.yaw - 5)
  elseif key == KEY_UP then
    camera.private.pitch = checkBoundary(camera.private.pitch + 5)
  elseif key == KEY_DOWN then
    camera.private.pitch = checkBoundary(camera.private.pitch - 5)
  end
end

function cameraUpdate()
  local pitch = camera.private.pitch * RADIANS_PER_DEGREE
  local yaw = camera.private.yaw * RADIANS_PER_DEGREE

  debugString = "pitch: "..camera.private.pitch.." yaw: "..camera.private.yaw

  local rotation = Quaternion(-yaw, camera.private.upVector.x, camera.private.upVector.y, camera.private.upVector.z)
  local cameraPosition = Vector3(0, 0, 0)
  cameraPosition.z = cameraPosition.z - camera.private.distance
  forward = Vector3(cameraPosition.x, cameraPosition.y, cameraPosition.z)
  if (forward:length() < 1) then 
    forward.set(1, 0, 0)
  end 

  local rigth = camera.private.upVector:crossProduct(forward)
  local roll = Quaternion(-pitch, rigth.x, rigth.y, rigth.z);

  -- actually I should multiply the matrix of rotation and roll with cameraPosition
  -- But there are no possibility in Lua.
  -- cameraPosition = rotation * roll * cameraPosition

  --cameraPosition = rotation:applyTo(cameraPosition)
  cameraPosition = roll:applyTo(cameraPosition)

  camera:setPosition(7,7,7)
  camera:setPosition(cameraPosition.x, cameraPosition.y, cameraPosition.z)
  camera:lookAt(Vector3(0,0,0), camera.private.upVector)
end

function Update(elapsed)
  cameraUpdate(elapsed)
end

