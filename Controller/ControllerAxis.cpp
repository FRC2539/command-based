#include "ControllerAxis.h"

#include "GenericController.h"

ControllerAxis::ControllerAxis(GenericController* control, std::string axis)
	: controller(control)
{
	axisNumber = controller->axes[axis];
	modifier = 1;
}

// To prevent a compiler warning
ControllerAxis::~ControllerAxis() {}


void ControllerAxis::setModifier(float mod)
{
	modifier = mod;
}

float ControllerAxis::getValue()
{
	return modifier * controller->GetAxis(axisNumber);
}
