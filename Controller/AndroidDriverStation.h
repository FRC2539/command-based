 
#ifndef ANDROID_DRIVER_STATION
#define ANDROID_DRIVER_STATION

#include "GenericController.h"

/*
 * This is for the Driver Station Android App by raystubbs
 */
class AndroidDriverStation : public GenericController {
public:
	static const uint32_t kDefaultXAxis = 1;
	static const uint32_t kDefaultYAxis = 2;
	static const uint32_t kDefaultZAxis = 4;
	static const uint32_t kDefaultTwistAxis = 3;
	static const uint32_t kDefaultThrottleAxis = 5;
	static const uint32_t kDefaultTriggerButton = 1;
	static const uint32_t kDefaultTopButton = 4;

	explicit AndroidDriverStation(uint32_t port=1);
	AndroidDriverStation(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);
	virtual ~AndroidDriverStation();

	virtual float GetAxisValue(uint32_t axis);

	enum Axes{
		LeftX = 1,
		LeftY = 2,
		RightX = 3,
		RightY = 4
	};

	enum Buttons{
		LeftNE = 1,
		LeftNW = 2,
		LeftSE = 3,
		LeftSW = 4,
		RightNE = 5,
		RightNW = 6,
		RightSE = 7,
		RightSW = 8
	};

protected:
	virtual void init();
	Joystick* secondJoystick;
};

#endif
