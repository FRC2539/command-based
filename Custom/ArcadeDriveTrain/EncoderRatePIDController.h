#ifndef ENCODER_RATE_PID_CONTROLLER
#define ENCODER_RATE_PID_CONTROLLER

#include "../SanePIDController.h"
class PIDSource;
class PIDOutput;

class EncoderRatePIDController : public SanePIDController {
public:
    EncoderRatePIDController(
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