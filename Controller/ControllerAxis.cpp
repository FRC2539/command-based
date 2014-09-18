#include "ControllerAxis.h"

#include "GenericController.h"

ControllerAxis::ControllerAxis(GenericController* control, uint32_t axisEnum)
	: controller(control), axis(axisEnum), modifier(1), throttle(false) {}

// To prevent a compiler warning
ControllerAxis::~ControllerAxis() {}

void ControllerAxis::setModifier(float mod)
{
	if (mod < -0.99 && mod > -1.01)
	{
		controller->invertedAxes.insert(axis);
		return;
	}
	if (mod > 0.99 && mod < 1.01)
	{
		controller->invertedAxes.erase(axis);
		return;
	}
	modifier = mod;
}

void ControllerAxis::invertAxis()
{
	if (controller->isInverted(axis))
	{
		controller->invertedAxes.erase(axis);
	}
	else
	{
		controller->invertedAxes.insert(axis);
	}
}

void ControllerAxis::makeThrottle()
{
	throttle = true;
}

float ControllerAxis::getValue()
{
	if (throttle)
	{
		return modifier * 0.5 * (controller->GetAxisValue(axis) + 1);
	}
	return modifier * controller->GetAxisValue(axis);
}
