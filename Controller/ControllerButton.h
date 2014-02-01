#ifndef CONTROLLER_BUTTON_H
#define CONTROLLER_BUTTON_H

#include "Buttons/JoystickButton.h"
#include "GenericController.h"

class ControllerButton : public JoystickButton
{
public:
	ControllerButton(GenericController* controller, std::string button);

private:
	static int getButtonNumber(
		GenericController* controller,
		std::string button
	);
};
#endif
