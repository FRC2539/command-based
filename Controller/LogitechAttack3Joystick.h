#ifndef LOGITECH_ATTACK3_JOYSTICK
#define LOGITECH_ATTACK3_JOYSTICK

#include "GenericController.h"

class LogitechAttack3Joystick : public GenericController {
public:
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 0;
	static const UINT32 kDefaultTwistAxis = 0;
	static const UINT32 kDefaultThrottleAxis = 3;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 2;

	explicit LogitechAttack3Joystick(UINT32 port);
	LogitechAttack3Joystick(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);
	
protected:
	virtual void init();
};

#endif
