#pragma once

#include "Buttons/JoystickButton.h"
#include "GenericController.h"

class ControllerButton : public JoystickButton
{
public:
	ControllerButton(GenericController* controller, int button);
};
