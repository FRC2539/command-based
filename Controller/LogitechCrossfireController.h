#ifndef LOGITECH_CROSSFIRE_CONTROLLER
#define LOGITECH_CROSSFIRE_CONTROLLER

#include "GenericController.h"

/*
 * This is the Logitech Gamepad with underside switch set to "X"
 * When Mode is off: the left joytick Y axis is axis 2
 * When Mode is on: the D-Pad Y axis is axis 2
 */
class LogitechCrossfireController : public GenericController {
public:
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 5;
	static const UINT32 kDefaultTwistAxis = 4;
	static const UINT32 kDefaultThrottleAxis = 3;
	static const UINT32 kDefaultTriggerButton = 3;
	static const UINT32 kDefaultTopButton = 4;
	
	explicit LogitechCrossfireController(UINT32 port);
	LogitechCrossfireController(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

protected:
	virtual void init();
};

#endif

