PI = 3.14159

scene = PhysicsScene(0, Vector3(200, 200, 200), false)

ground = ScenePrimitive(ScenePrimitive.TYPE_PLANE, 15, 15)
ground:setColor(0, 1, .5, 1)
scene:addPhysicsChild(ground, PhysicsEntity.SHAPE_PLANE, 0, 1, 0, 1, false)

box = ScenePrimitive(ScenePrimitive.TYPE_BOX, 1,1,1)
box:setColor(1,.5,0,1)
box:setPosition(0, .5, 0)
scene:addPhysicsChild(box, PhysicsEntity.SHAPE_BOX, 100, .8, .8, 1, false)

controller = ScenePrimitive(ScenePrimitive.TYPE_BOX, .5, 1, .5)
controller:setColor(1,0,0,1)
controller:setPosition(0, 3, 0)
playerController = scene:addCharacterChild(controller, 10, 1, .5, 1)

camera = Camera(scene)
controller:addChild(camera)
scene:setActiveCamera(camera)

modifyMouse = -1
enableMouse = false
walkSpeed = 12
strafeSpeed = 10
maxPitch = PI/7
minPitch = -PI/8
rotationSpeedY = maxPitch / 10
rotationSpeedX = maxPitch / 12

center = {
  ["x"] = 640 * .5,
  ["y"] = 480 * .5
}

mouse = {
  ["x"] = center.x,
  ["y"] = center.y
}

player = {
  ["walkSpeed"] = 0,
  ["strafeSpeed"] = 0,
  ["direction"] = 0,
  ["pitch"] = 0   
}

input = {}

CoreServices.getInstance():getCore():warpCursor(center.x, center.y)
CoreServices.getInstance():getCore():enableMouse(enableMouse)

function onKeyDown(key)
  input[key] = true
end

function onMouseMove(x,y)
  mouse.x = x
  mouse.y = y 
end

function Update(elapsed)
  local pWalkSpeed = 0
  local pStrafeSpeed = 0

  if input[KEY_r] then
    playerController:warpCharacter(Vector3(0, 3, 0))
  end

  if input[KEY_ESCAPE] then
    enableMouse = not enableMouse
    CoreServices.getInstance():getCore():enableMouse(enableMouse)
  end

  if input[KEY_SPACE] then
    playerController:jump()
  end

  if input[KEY_w] then
    pWalkSpeed = -walkSpeed * elapsed
  end

  if input[KEY_s] then
    pWalkSpeed = walkSpeed * elapsed
  end

  if input[KEY_a] then
    pStrafeSpeed = -strafeSpeed * elapsed
  end

  if input[KEY_d] then
    pStrafeSpeed = strafeSpeed * elapsed
  end

  input = {}

  if enableMouse then return end

  local pitch = player.pitch + (elapsed * rotationSpeedX * (modifyMouse * (center.y - mouse.y)))
  if pitch > maxPitch then
    pitch = maxPitch
  elseif pitch < minPitch then
    pitch = minPitch
  end

  local pDirection = player.direction + (elapsed * rotationSpeedY * (center.x - mouse.x))

  player.walkSpeed = pWalkSpeed
  player.strafeSpeed = pStrafeSpeed
  player.direction = pDirection
  player.pitch = pitch

  camera:setPitch(pitch * (180 / PI))
  controller:setYaw(pDirection * (180/PI))

  local pdir = Vector3(pWalkSpeed * sin(pDirection), 0, pWalkSpeed * cos(-pDirection))
  pdir.x = pdir.x + (pStrafeSpeed * cos(pDirection))
  pdir.z = pdir.z + (pStrafeSpeed * sin(-pDirection))

  playerController:setWalkDirection(pdir)

  CoreServices.getInstance():getCore():warpCursor(center.x, center.y)
  mouse.x, mouse.y = center.x, center.y
end
