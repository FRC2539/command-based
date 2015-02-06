#ifndef LOGITECH_CROSSFIRE_CONTROLLER
#define LOGITECH_CROSSFIRE_CONTROLLER

#include "GenericController.h"

/*
 * This is the Logitech Gamepad with underside switch set to "X"
 * When Mode is off: the left joystick Y axis is axis 2
 * When Mode is on: the D-Pad Y axis is axis 2
 */
class LogitechCrossfireController : public GenericController {
public:
	static const uint32_t kDefaultXAxis = 1;
	static const uint32_t kDefaultYAxis = 2;
	static const uint32_t kDefaultZAxis = 5;
	static const uint32_t kDefaultTwistAxis = 4;
	static const uint32_t kDefaultThrottleAxis = 3;
	static const uint32_t kDefaultTriggerButton = 3;
	static const uint32_t kDefaultTopButton = 4;
	
	explicit LogitechCrossfireController(uint32_t port);
	LogitechCrossfireController(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);

	enum Axes{
		LeftX = 0,
		LeftY = 1,
		RightX = 3,
		RightY = 4,
		LeftTrigger = 2,
		RightTrigger = 2,
		DPadX = 5,
		DPadY = 1
	};

	enum Buttons{
		A = 1,
		B = 2,
		X = 3,
		Y = 4,
		LeftBumper = 5,
		RightBumper = 6,
		Back = 7,
		Start = 8,
		LeftJoystick = 9,
		RightJoystick = 10
	};

protected:
	virtual void init();
};

#endif

