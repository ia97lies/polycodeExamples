//----------------------------------------------------------------------------
// The MIT License
// Took the basics from Polycode Examples
//----------------------------------------------------------------------------

#include "HelloPolycodeApp.h"

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) {

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
            fprintf(stderr, "Key left pressed\n");
            fflush(stderr);
					break;
					case KEY_RIGHT:
            fprintf(stderr, "Key left pressed\n");
            fflush(stderr);
					break;
				}
			break;
			case InputEvent::EVENT_KEYUP:
				switch (inputEvent->key) {
					case KEY_LEFT:
					case KEY_RIGHT:
            fprintf(stderr, "Key released\n");
            fflush(stderr);
					break;					
				}
			break;			
		}
		
	}
}

bool HelloPolycodeApp::Update() {
    return core->updateAndRender();
}
