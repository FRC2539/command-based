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
	typedef enum
	{
		kXAxis = 1,
		kYAxis = 2,
		kThrottleAxis = 3
	} AxisType;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 2;
	typedef enum
	{
		kTriggerButton = 1,
		kTopButton = 2,
		k2Button = 2,
		k3Button = 3,
		k4Button = 4,
		k5Button = 5,
		k6Button = 6,
		k7Button = 7,
		k8Button = 8,
		k9Button = 9,
		k10Button = 10,
		k11Button = 11
	} ButtonType;

	explicit LogitechAttack3Joystick(UINT32 port);
	LogitechAttack3Joystick(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

protected:
	virtual void init();
};

#endif
