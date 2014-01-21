 
#ifndef LOGITECH_DUAL_SHOCK_CONTROLLER
#define LOGITECH_DUAL_SHOCK_CONTROLLER

#include "GenericController.h"

/*
 * This is the Logitech Gamepad with underside switch set to "D"
 * This class assumes mode is off. If mode is on, the D-Pad and right joystick
 *   are swapped.
 */
class LogitechDualShockController : public GenericController {
public:
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 4;
	static const UINT32 kDefaultTwistAxis = 3;
	static const UINT32 kDefaultThrottleAxis = 5;
	typedef enum
	{
		kLeftXAxis = 1,
		kLeftYAxis = 2,
		kRightXAxis = 3,
		kRightYAxis = 4,
		kDPadXAxis = 5,
		kDPadYAxis = 6
	} AxisType;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 4;
	typedef enum
	{
		kAButton = 2,
		kBButton = 3,
		kXButton = 1,
		kYButton = 4,
		kLeftBumperButton = 5,
		kRightBumperButton = 6,
		kLeftTriggerButton = 7,
		kRightTriggerButton = 8,
		kBackButton = 9,
		kStartButton = 10,
		kLeftJoystickButton = 11,
		kRightJoystickButton = 12
	} ButtonType;

	explicit LogitechDualShockController(UINT32 port);
	LogitechDualShockController(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

protected:
	virtual void init();
};

#endif
