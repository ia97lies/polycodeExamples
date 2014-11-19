-- Physics3d. basic 3d physics scene

-- initialise scene
scene = PhysicsScene(60, Vector3(30,30,30), false)

-- add ground
ground = ScenePrimitive(ScenePrimitive.TYPE_PLANE, 8,8)
ground.rigidBody = true
ground:loadTexture("Resources/green_texture.png")
scene:addCollisionChild(ground, PhysicsEntity.SHAPE_PLANE, 1)

-- add 30 cubes
for i=0,29 do
   box =  ScenePrimitive(ScenePrimitive.TYPE_BOX, 1,1,1)
   box:loadTexture("Resources/blue_texture.png")
   box:setPosition( 2*random(), (8.0 + (16*random())), 2*random() )
--   scene:setSpin(box, vector3(,random(),random()) )
   box.rigidBody = true
   scene:addPhysicsChild(box, PhysicsEntity.SHAPE_BOX, 1, 0.5, 0, 1, false)
end

scene:getDefaultCamera():setPosition(7,7,7)
scene:getDefaultCamera():lookAt(Vector3(0,0,0), Vector3(0,1,0))

