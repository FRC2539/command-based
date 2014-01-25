#include "GenericController.h"

GenericController::GenericController(UINT32 port) : Joystick(port){}

GenericController::GenericController(
        UINT32 port,
        UINT32 numAxisTypes,
        UINT32 numButtonTypes
    ): Joystick(
        port,
        numAxisTypes,
        numButtonTypes
    ){}

float GenericController::GetAxis(UINT32 axis)
{
	if (isInverted(axis))
	{
		return -1 * Joystick::GetRawAxis(axis);
	}
	else
	{
		return Joystick::GetRawAxis(axis);
	}
	return GetRawAxis(axis);
}

float GenericController::GetX()
{
	return GetAxis(kDefaultXAxis);
}

float GenericController::GetY()
{
	return GetAxis(kDefaultYAxis);
}

float GenericController::GetZ()
{
	return GetAxis(kDefaultZAxis);
}

float GenericController::GetTwist()
{
	return GetAxis(kDefaultTwistAxis);
}

float GenericController::GetThrottle()
{
	return GetAxis(kDefaultThrottleAxis);
}

bool GenericController::isInverted(UINT32 axis)
{
	return (invertedAxes.count(axis) == 1);
}

float GenericController::GetAxis(std::string axis)
{
	return GetAxis(axes[axis]); 
}
