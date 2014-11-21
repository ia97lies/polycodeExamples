//----------------------------------------------------------------------------
// The MIT License
// Took the basics from Polycode Examples
//----------------------------------------------------------------------------

#include "HelloPolycodeApp.h"

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) : EventHandler() {

	core = new POLYCODE_CORE(view, 640,480,false,true,0,0,90, 0, true);

	CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	scene = new Scene(Scene::SCENE_3D);
	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 5,5);
	ground->loadTexture("Resources/green_texture.png");
	scene->addEntity(ground);

	ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 1,1,1);
	box->loadTexture("Resources/pink_texture.png");
	box->setPosition(0.0, 0.5, 0.0);
	scene->addEntity(box);

  core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
  core->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);

  pitch = 20.0f;
  yaw = 0.0f;
  distance = 15.0f;
  upVector = Vector3(0.0f, 1.0f, 0.0f);
  target = Vector3(0.0f, 0.0f, 0.0f);

  cameraUpdate();
}

HelloPolycodeApp::~HelloPolycodeApp() {
}

void HelloPolycodeApp::handleEvent(Event *e) {
	if(e->getDispatcher() == core->getInput()) {
		InputEvent *inputEvent = (InputEvent*)e;
		
		switch(e->getEventCode()) {
			case InputEvent::EVENT_KEYDOWN:
				switch (inputEvent->keyCode()) {
					case KEY_LEFT:
            rotateCamera(yaw, +CAMERA_STEP_SIZE); 
					break;
					case KEY_RIGHT:
            rotateCamera(yaw, -CAMERA_STEP_SIZE);
					break;
					case KEY_UP:
            rotateCamera(pitch, +CAMERA_STEP_SIZE);
					break;
					case KEY_DOWN:
            rotateCamera(pitch, -CAMERA_STEP_SIZE);
					break;

				}
        cameraUpdate();
			break;
		}
		
	}
}

void HelloPolycodeApp::rotateCamera(float &angle, float value) {
  angle -= value; 
  if (angle < 0) angle += 360; 
  if (angle >= 360) angle -= 360;
}


void HelloPolycodeApp::cameraUpdate() {
  // my first try with quaternion do not work, I tried to do the same as 
  // with the bullet lib quaternion but not possible so far:
  // position = btMatrix3x3(rotationQ) * btMatrix3x3(roll) * postion
  // => not possible with Polycode math

  // our values represent the angles in degrees, but 3D 
  // math typically demands angular values are in radians.
  float pitchRad = pitch * RADIANS_PER_DEGREE;
  float yawRad = yaw * RADIANS_PER_DEGREE;

  // apply pitch
  float x = 0;
  float y = cos(pitchRad) * distance;
  float z = sin(pitchRad) * distance;
  // apply yaw
  // TODO

  Vector3 position = Vector3(x, y, z);
	scene->getDefaultCamera()->setPosition(position);
	scene->getDefaultCamera()->lookAt(target);
}

bool HelloPolycodeApp::Update() {
    return core->updateAndRender();
}

