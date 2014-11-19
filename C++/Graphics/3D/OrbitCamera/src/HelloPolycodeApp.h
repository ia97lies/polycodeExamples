//----------------------------------------------------------------------------
// The MIT License
// Took the basics from Polycode Examples
//----------------------------------------------------------------------------

#include <Polycode.h>
#include "PolycodeView.h"

using namespace Polycode;

#define RADIANS_PER_DEGREE 0.01745329f
#define CAMERA_STEP_SIZE 5.0f

class HelloPolycodeApp : public EventHandler {
public:
    HelloPolycodeApp(PolycodeView *view);
    ~HelloPolycodeApp();
    void handleEvent(Event *e);
    bool Update();
    
private:
	Core *core;
  float pitch;
  float yaw;
  float distance;

  void rotateCamera(float &angle, float value);
  void cameraUpdate(); 
};
