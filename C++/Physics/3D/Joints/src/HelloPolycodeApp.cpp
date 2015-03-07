#include "unistd.h"
#include "HelloPolycodeApp.h"

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) {

	core = new POLYCODE_CORE(view, 640,480,false,true,0,0,90, 0, true);

	CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	PhysicsScene *scene = new PhysicsScene();

	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 10, 10);
	ground->loadTexture("Resources/green_texture.png");
	scene->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

  ScenePrimitive *box1 = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 0.5,0.5,0.5);
  box1->loadTexture("Resources/pink_texture.png");
  box1->setPosition(0,4,0);
  scene->addEntity(box1);

  ScenePrimitive *box2 = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 0.5,0.5,0.5);
  box2->loadTexture("Resources/pink_texture.png");
  box2->setPosition(1,0,0);
  box1->addChild(box2);

  scene->trackPhysicsChild(box1, PhysicsSceneEntity::SHAPE_BOX, 1.0);
  scene->trackPhysicsChild(box2, PhysicsSceneEntity::SHAPE_BOX, 1.0);

  PhysicsHingeConstraint *constraint1 = scene->createHingeConstraint(box1, Vector3(0,0,0), Vector3(0,1,0), 0, 0);
  // PhysicsHingeConstraint *createHingeJoint(Entity *entity1, Entity *entity2, Vector3 pivot1, Vector3 axis1, Vector3 pivot2, Vector3 axis2, Number minLimit, Number maxLimit);
  PhysicsHingeConstraint *constraint2 = scene->createHingeJoint(box1, box2, Vector3(0,0,0), Vector3(0,1,0), Vector3(-1,0,0), Vector3(0,1,0), 0, /*165 * 3.14159265 / 180*/100);
  constraint2->btConstraint->enableAngularMotor(true, 1, 1);

  //scene->removeConstraint(constraint1);

	scene->getDefaultCamera()->setPosition(7,7,7);
	scene->getDefaultCamera()->lookAt(Vector3(0,0,0));
}

HelloPolycodeApp::~HelloPolycodeApp() {
}

bool HelloPolycodeApp::Update() {
    return core->updateAndRender();
}
