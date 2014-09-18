#include "GenericController.h"

GenericController::GenericController(uint32_t port) : Joystick(port) {}

GenericController::GenericController(
		uint32_t port,
		uint32_t numAxisTypes,
		uint32_t numButtonTypes
	) : Joystick(
		port,
		numAxisTypes,
		numButtonTypes
	){}

float GenericController::GetAxisValue(uint32_t axis)
{
	if (isInverted(axis))
	{
		return -1 * Joystick::GetRawAxis(axis);
	}

	return Joystick::GetRawAxis(axis);
}

float GenericController::GetX()
{
	return GetAxisValue(kDefaultXAxis);
}

float GenericController::GetY()
{
	return GetAxisValue(kDefaultYAxis);
}

float GenericController::GetZ()
{
	return GetAxisValue(kDefaultZAxis);
}

float GenericController::GetTwist()
{
	return GetAxisValue(kDefaultTwistAxis);
}

float GenericController::GetThrottle()
{
	return GetAxisValue(kDefaultThrottleAxis);
}

bool GenericController::isInverted(uint32_t axis)
{
	return (invertedAxes.count(axis) == 1);
}

bool GenericController::IsButtonPressed(unsigned int button)
{
	return GetRawButton(button);
}
