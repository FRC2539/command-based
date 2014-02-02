#include "ControllerButton.h"

ControllerButton::ControllerButton(
		GenericController* controller,
		std::string button
	)
	: JoystickButton(
		controller,
		ControllerButton::getButtonNumber(controller, button)
	){}

int ControllerButton::getButtonNumber(
		GenericController* controller,
		std::string button
	)
{
	return controller->buttons[button];
}
