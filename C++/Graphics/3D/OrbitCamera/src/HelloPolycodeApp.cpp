//----------------------------------------------------------------------------
// The MIT License
// Took the basics from Polycode Examples
//----------------------------------------------------------------------------

#include "HelloPolycodeApp.h"

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) : EventHandler() {

	core = new POLYCODE_CORE(view, 640,480,false,true,0,0,90, 0, true);

	CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	Scene *scene = new Scene(Scene::SCENE_3D);
	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 5,5);
	ground->loadTexture("Resources/green_texture.png");
	scene->addEntity(ground);

	ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 1,1,1);
	box->loadTexture("Resources/pink_texture.png");
	box->setPosition(0.0, 0.5, 0.0);
	scene->addEntity(box);
	
	scene->getDefaultCamera()->setPosition(7,7,7);
	scene->getDefaultCamera()->lookAt(Vector3(0,0,0));

  core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
  core->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);

  pitch = 20.0f;
  yaw = 0.0f;
  distance = 15.0f;
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
            fprintf(stderr, "yaw: %f\n", yaw);
            fflush(stderr);
					break;
					case KEY_RIGHT:
            rotateCamera(yaw, -CAMERA_STEP_SIZE);
            fprintf(stderr, "yaw: %f\n", yaw);
            fflush(stderr);
					break;
					case KEY_UP:
            rotateCamera(pitch, +CAMERA_STEP_SIZE);
            fprintf(stderr, "pitch: %f\n", pitch);
            fflush(stderr);
					break;
					case KEY_DOWN:
            rotateCamera(pitch, -CAMERA_STEP_SIZE);
            fprintf(stderr, "pitch: %f\n", pitch);
            fflush(stderr);
					break;

				}
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
  // our values represent the angles in degrees, but 3D 
  // math typically demands angular values are in radians.
  float pitchRad = pitch * RADIANS_PER_DEGREE;
  float yawRad = yaw * RADIANS_PER_DEGREE;

  // create a quaternion defining the angular rotation 
  // around the up vector
  Quaternion rotation(yawRad, 0.0f, 1.0f, 0.0f);
  Vector3 position(0.0f, 0.0f, -distance);

#if 0
  // set the camera's position to 0,0,0, then move the 'z' 
  // position to the current value of m_cameraDistance.
  btVector3 cameraPosition(0,0,0);
  cameraPosition[2] = -m_cameraDistance;

  fprintf(stderr, "cameraTarget x:%f, y:%f, z:%f\n", m_cameraTarget[0], m_cameraTarget[1], m_cameraTarget[2]);
  fprintf(stderr, "cameraPos x:%f, y:%f, z:%f\n", cameraPosition[0], cameraPosition[1], cameraPosition[2]);

  // create a Bullet Vector3 to represent the camera 
  // position and scale it up if its value is too small.
  btVector3 forward(cameraPosition[0], cameraPosition[1], cameraPosition[2]);
  if (forward.length2() < SIMD_EPSILON) {
    forward.setValue(1.f,0.f,0.f);
  }

  // figure out the 'right' vector by using the cross 
  // product on the 'forward' and 'up' vectors
  btVector3 right = m_upVector.cross(forward);

  // create a quaternion that represents the camera's roll
  btQuaternion roll(right, - pitchRad);

  // turn the rotation (around the Y-axis) and roll (around 
  // the forward axis) into transformation matrices and 
  // apply them to the camera position. This gives us the 
  // final position
  cameraPosition = btMatrix3x3(rotation) * btMatrix3x3(roll) * cameraPosition;
  fprintf(stderr, "newCameraPos x:%f, y:%f, z:%f\n", cameraPosition[0], cameraPosition[1], cameraPosition[2]);

  // save our new position in the member variable, and 
  // shift it relative to the target position (so that we 
  // orbit it)
  m_cameraPosition[0] = cameraPosition.getX();
  m_cameraPosition[1] = cameraPosition.getY();
  m_cameraPosition[2] = cameraPosition.getZ();
  m_cameraPosition += m_cameraTarget;

  // create a view matrix based on the camera's position and where it's
  // looking
  gluLookAt(m_cameraPosition[0], 
            m_cameraPosition[1], 
            m_cameraPosition[2], 
            m_cameraTarget[0], 
            m_cameraTarget[1], 
            m_cameraTarget[2], 
            m_upVector.getX(), 
            m_upVector.getY(), 
            m_upVector.getZ());
  // the view matrix is now set
#endif
}

bool HelloPolycodeApp::Update() {
    return core->updateAndRender();
}

