#include "OI.h"

#include "Controller/ControllerFactory.h"
#include "Controller/GenericController.h"
#include "Controller/ControllerButton.h"
#include "ControllerMap.h"

#include "Commands/Types/ToggleCommand.h"
#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/ResetCommand.h"

OI::OI()
{
	std::unordered_map<int, std::string> controller_map = CONTROLLERS;
	for (auto controller : controller_map)
	{
		controllers[controller.first] = ControllerFactory::makeController(
			controller.second,
			controller.first
		);
	}
	
	preciseMovementButton = getControllerButton(PRECISE_MOVEMENT_BUTTON);
	preciseMovementButton->WhenPressed(
		new ToggleCommand(new PreciseArcadeDriveCommand())
	);
	
	resetButton = getControllerButton(RESET_BUTTON);
	resetButton->WhenPressed(new ResetCommand());

}

OI::~OI()
{
	delete preciseMovementButton;
	delete resetButton;

	for (auto controller : controllers)
	{
		delete controller.second;
	}
}

GenericController* OI::getController(int port)
{
	return controllers[port];
}

float OI::getAxis(int port, std::string axis, float modifier)
{
	return modifier * getController(port)->GetAxis(axis);
}

bool OI::getButton(int port, std::string button)
{
	return getController(port)->GetButton(button);
}

ControllerButton* OI::getControllerButton(std::string button)
{
	return getControllerButton(1, button);
}


ControllerButton* OI::getControllerButton(int port, std::string button)
{
	return new ControllerButton(getController(port), button);
}
