#include "LogitechAttack3Joystick.h"

LogitechAttack3Joystick::LogitechAttack3Joystick(UINT32 port)
	: GenericController(port) {
		init();
	}

LogitechAttack3Joystick::LogitechAttack3Joystick(
		UINT32 port,
		UINT32 numAxisTypes,
		UINT32 numButtonTypes
	): GenericController(
		port,
		numAxisTypes,
		numButtonTypes
	){
		init();
	}

void LogitechAttack3Joystick::init()
{
	invertedAxes = {kYAxis, kThrottleAxis};
}

