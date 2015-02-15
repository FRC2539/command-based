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
	float value = controller->GetAxisValue(axis);
	if (value < 0.1 && value > -0.1)
	{
		value = 0;
	}
	if (throttle)
	{
		return modifier * 0.5 * (value + 1);
	}
	return modifier * value;
}
