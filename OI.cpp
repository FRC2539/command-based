#include "OI.h"
#include "Controller/ControllerFactory.h"
#include "Controller/ControllerButton.h"
#include "Commands/PreciseArcadeDriveCommand.h"

OI::OI() {
	// Process operator interface input here.
	controller = ControllerFactory::makeController(DRIVER_CONTROLLER_TYPE,DRIVE_CONTROLLER_PORT);
	preciseMovementButton = new ControllerButton(controller, PRECISE_MOVEMENT_BUTTON);
	preciseMovementButton->WhileHeld(new PreciseArcadeDriveCommand());

}

OI::~OI() {
	delete controller;
	delete preciseMovementButton;
}

GenericController* OI::getController() {
	return controller;
}

