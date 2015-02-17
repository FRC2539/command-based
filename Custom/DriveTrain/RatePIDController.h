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
		PIDSource* source,
		PIDOutput* output
	);

	virtual void StartLiveWindowMode();

protected:
	virtual void Calculate();

	float scaleInput(float input);
};

#endif