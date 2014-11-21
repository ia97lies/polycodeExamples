//----------------------------------------------------------------------------
// The MIT License
// Took the basics from Polycode Examples
//----------------------------------------------------------------------------

#include <Polycode.h>
#include "PolycodeView.h"
#include "bullet/LinearMath/btVector3.h"
#include "bullet/LinearMath/btMatrix3x3.h"
#include "bullet/LinearMath/btQuaternion.h"

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
	Core *m_core;
  Scene *m_scene;
  float m_pitch;
  float m_yaw;
  float m_distance;
  btVector3 m_upVector;
  Vector3 m_position;
  Vector3 m_target;

  void rotateCamera(float &angle, float value);
  void cameraUpdate(); 
};
