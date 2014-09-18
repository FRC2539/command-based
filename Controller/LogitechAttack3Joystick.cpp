#include "LogitechAttack3Joystick.h"

CONTROLLER_SETUP(LogitechAttack3Joystick)

void LogitechAttack3Joystick::init()
{
	invertedAxes = {Y, Throttle};
}

