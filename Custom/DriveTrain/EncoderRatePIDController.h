#ifndef ENCODER_RATE_PID_CONTROLLER
#define ENCODER_RATE_PID_CONTROLLER

#include <PIDController.h>
class PIDSource;
class PIDOutput;

class EncoderRatePIDController : public PIDController {
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
};

#endif