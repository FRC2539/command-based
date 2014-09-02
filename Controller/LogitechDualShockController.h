 
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
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 4;
	static const UINT32 kDefaultTwistAxis = 3;
	static const UINT32 kDefaultThrottleAxis = 5;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 4;
	
	explicit LogitechDualShockController(UINT32 port);
	LogitechDualShockController(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

protected:
	virtual void init();
	
};

#endif
