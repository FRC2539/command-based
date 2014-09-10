#include "ControllerAxis.h"

#include "GenericController.h"

ControllerAxis::ControllerAxis(GenericController* control, const char* axisName)
	: controller(control), axis(axisName), modifier(1), throttle(false) {}

// To prevent a compiler warning
ControllerAxis::~ControllerAxis() {}

void ControllerAxis::setModifier(float mod)
{
	if (mod < -0.99 && mod > -1.01)
	{
		controller->invertedAxes.insert(controller->axes[axis]);
		return;
	}
	if (mod > 0.99 && mod < 1.01)
	{
		controller->invertedAxes.erase(controller->axes[axis]);
		return;
	}
	modifier = mod;
}

void ControllerAxis::invertAxis()
{
	if (controller->isInverted(controller->axes[axis]))
	{
		controller->invertedAxes.erase(controller->axes[axis]);
	}
	else
	{
		controller->invertedAxes.insert(controller->axes[axis]);
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
		return modifier * 0.5 * (controller->GetAxis(axis) + 1);
	}
	return modifier * controller->GetAxis(axis);
}
