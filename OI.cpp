#include "OI.h"

#include "Controller/ControllerFactory.h"
#include "Controller/GenericController.h"
#include "Controller/ControllerButton.h"
#include "ControllerMap.h"

#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/FireCommandGroup.h"
#include "Commands/ResetCommand.h"
#include "Commands/DrawBackCommandGroup.h"

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
	fireButton->WhenPressed(new FireCommandGroup());

	drawBackButton = getControllerButton(DRAWBACK_BUTTON);
	drawBackButton->WhenPressed(new DrawBackCommandGroup());

	resetButton = getControllerButton(RESET_BUTTON);
	resetButton->WhenPressed(new ResetCommand());
	
}

OI::~OI() {
	delete preciseMovementButton;
	delete fireButton;
	delete drawBackButton;
	delete resetButton;
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
