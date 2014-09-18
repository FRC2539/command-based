#include "AndroidDriverStation.h"

CONTROLLER_SETUP(AndroidDriverStation)

AndroidDriverStation::~AndroidDriverStation()
{
	delete secondJoystick;
}

void AndroidDriverStation::init()
{
	invertedAxes = {LeftY, RightY};

	secondJoystick = new Joystick(2);
}

float AndroidDriverStation::GetAxisValue(uint32_t axis)
{
	if (axis <= 2)
	{
		return GenericController::GetAxisValue(axis);
	}

	uint32_t axisNumber = axis - 2;

	if (isInverted(axis))
	{
		return -1 * secondJoystick->GetRawAxis(axisNumber);
	}

	return secondJoystick->GetRawAxis(axisNumber);
}
