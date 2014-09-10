#include "ControllerButton.h"

ControllerButton::ControllerButton(
		GenericController* controller,
		const char* button
	)
	: JoystickButton(
		controller,
		ControllerButton::getButtonNumber(controller, button)
	){}

int ControllerButton::getButtonNumber(
		GenericController* controller,
		const char* button
	)
{
	return controller->buttons[button];
}
