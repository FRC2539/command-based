#include "OI.h"

#include "Controller/ControllerFactory.h"
#include "Controller/GenericController.h"
#include "Controller/ControllerButton.h"
#include "ControllerMap.h"

#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/FireCommand.h"
#include "Commands/OpenCommand.h"
#include "Commands/CloseCommand.h"
#include "Commands/ResetCommand.h"
#include "Commands/DrawBackCommand.h"
#include "Commands/ResetCommand.h"

OI::OI() {
	std::unordered_map<int, std::string> controller_map = CONTROLLERS;
	for (auto controller : controller_map)
	{
		controllers[controller.first] = ControllerFactory::makeController(
			controller.second, 
			controller.first
		);
	}
	
	preciseMovementButton = getControllerButton(PRECISE_MOVEMENT_BUTTON);
	preciseMovementButton->WhenPressed(new PreciseArcadeDriveCommand());

	
	fireButton = getControllerButton(FIRE_BUTTON);
	fireButton->WhenPressed(new FireCommand());

	drawBackButton = getControllerButton(DRAWBACK_BUTTON);
	drawBackButton->WhenPressed(new DrawBackCommand());

	resetButton = getControllerButton(RESET_BUTTON);
	resetButton->WhenPressed(new ResetCommand());
	
	openButton = getControllerButton(OPEN_BUTTON);
	openButton->WhenPressed(new OpenCommand());
	
	closeButton = getControllerButton(CLOSE_BUTTON);
	closeButton->WhenPressed(new CloseCommand());
}

OI::~OI() {
	delete preciseMovementButton;
	delete fireButton;
	delete resetButton;
	delete openButton;
	delete closeButton;
}

GenericController* OI::getController(int port)
{
	return controllers[port];
}

float OI::getAxis(int port, std::string axis)
{
	return getController(port)->GetAxis(axis);
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
