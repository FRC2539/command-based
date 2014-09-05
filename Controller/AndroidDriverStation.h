 
#ifndef ANDROID_DRIVER_STATION
#define ANDROID_DRIVER_STATION

#include "GenericController.h"

/*
 * This is for the Driver Station Android App by raystubbs
 */
class AndroidDriverStation : public GenericController {
public:
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 4;
	static const UINT32 kDefaultTwistAxis = 3;
	static const UINT32 kDefaultThrottleAxis = 5;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 4;
	
	explicit AndroidDriverStation(UINT32 port=1);
	AndroidDriverStation(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);
    virtual ~AndroidDriverStation();

	virtual float GetAxis(std::string axis);

protected:
	virtual void init();
	Joystick* secondJoystick;
	std::unordered_set<std::string> secondJoystickAxes;
};

#endif
