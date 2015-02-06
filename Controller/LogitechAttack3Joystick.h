#ifndef LOGITECH_ATTACK3_JOYSTICK
#define LOGITECH_ATTACK3_JOYSTICK

#include "GenericController.h"

class LogitechAttack3Joystick : public GenericController {
public:
	static const uint32_t kDefaultXAxis = 1;
	static const uint32_t kDefaultYAxis = 2;
	static const uint32_t kDefaultZAxis = 0;
	static const uint32_t kDefaultTwistAxis = 0;
	static const uint32_t kDefaultThrottleAxis = 3;
	static const uint32_t kDefaultTriggerButton = 1;
	static const uint32_t kDefaultTopButton = 3;

	explicit LogitechAttack3Joystick(uint32_t port);
	LogitechAttack3Joystick(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);

	enum Axes{
		X = 0,
		Y = 1,
		Throttle = 2
	};

	enum Buttons{
		Trigger = 1,
		TopFront = 3,
		TopLeft = 4,
		TopRight = 5,
		TopBack = 2,
		LeftFront = 6,
		LeftBack = 7,
		BackLeft = 8,
		BackRight = 9,
		RightFront = 11,
		RightBack = 10
	};
	
protected:
	virtual void init();
};

#endif
