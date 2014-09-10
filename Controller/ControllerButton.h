#ifndef CONTROLLER_BUTTON_H
#define CONTROLLER_BUTTON_H

#include "Buttons/JoystickButton.h"
#include "GenericController.h"

class ControllerButton : public JoystickButton
{
public:
	ControllerButton(GenericController* controller, const char* button);

private:
	static int getButtonNumber(
		GenericController* controller,
		const char* button
	);
};
#endif
