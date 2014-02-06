#include "OI.h"
#include "Controller/ControllerFactory.h"
#include "Controller/ControllerButton.h"
#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/FireCommand.h"

OI::OI() {
	// Process operator interface input here.
	controller = ControllerFactory::makeController(DRIVER_CONTROLLER_TYPE,DRIVE_CONTROLLER_PORT);
	preciseMovementButton = new ControllerButton(controller, PRECISE_MOVEMENT_BUTTON);
	preciseMovementButton->WhenPressed(new PreciseArcadeDriveCommand());
	fireButton = new ControllerButton(controller, FIRE_BUTTON);
	fireButton->WhenPressed(new FireCommand());

}

OI::~OI() {
	delete controller;
	delete preciseMovementButton;
	delete fireButton;
}

GenericController* OI::getController() {
	return controller;
}

