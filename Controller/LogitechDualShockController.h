 
#ifndef LOGITECH_DUAL_SHOCK_CONTROLLER
#define LOGITECH_DUAL_SHOCK_CONTROLLER

#include "GenericController.h"

/*
 * This is the Logitech Gamepad with underside switch set to "D"
 * This class assumes mode is off. If mode is on, the D-Pad and right joystick
 * are swapped.
 */
class LogitechDualShockController : public GenericController {
public:
	static const uint32_t kDefaultXAxis = 1;
	static const uint32_t kDefaultYAxis = 2;
	static const uint32_t kDefaultZAxis = 4;
	static const uint32_t kDefaultTwistAxis = 3;
	static const uint32_t kDefaultThrottleAxis = 5;
	static const uint32_t kDefaultTriggerButton = 1;
	static const uint32_t kDefaultTopButton = 4;
	
	explicit LogitechDualShockController(uint32_t port);
	LogitechDualShockController(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);

	enum Axis{
		LeftX = 1,
		LeftY = 2,
		RightX = 3,
		RightY = 4,
		DPadX = 5,
		DPadY = 6
	};

	enum Buttons{
		A = 2,
		B = 3,
		X = 1,
		Y = 4,
		LeftBumper = 5,
		RightBumper = 6,
		LeftTrigger = 7,
		RightTrigger = 8,
		Back = 9,
		Start = 10,
		LeftJoystick = 11,
		RightJoystick = 12
	};

protected:
	virtual void init();
	
};

#endif
