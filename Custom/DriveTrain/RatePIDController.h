#ifndef RATE_PID_CONTROLLER
#define RATE_PID_CONTROLLER

#include "../SanePIDController.h"
class PIDSource;
class PIDOutput;

class RatePIDController : public SanePIDController {
public:
    RatePIDController(
		float p,
		float i,
		float d,
		float f,
		PIDSource *source,
		PIDOutput *output
	);

	virtual void StartLiveWindowMode();

protected:
	virtual void Calculate();
};

#endif