#include "ControllerAxis.h"

#include "GenericController.h"

ControllerAxis::ControllerAxis(GenericController* control, std::string axisName)
	: controller(control), axis(axisName)
{
	modifier = 1;
	throttle = false;
}

// To prevent a compiler warning
ControllerAxis::~ControllerAxis() {}

void ControllerAxis::setModifier(float mod)
{
	modifier = mod;
}

void ControllerAxis::makeThrottle()
{
	throttle = true;
}

float ControllerAxis::getValue()
{
	if (throttle)
	{
		return modifier * 0.5 * (controller->GetAxis(axis) + 1);
	}
	return modifier * controller->GetAxis(axis);
}
