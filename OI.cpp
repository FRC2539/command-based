#include "OI.h"
#include "Controller/ControllerFactory.h"
#include "Controller/ControllerButton.h"
#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/FireCommand.h"
#include "Commands/OpenCommand.h"
#include "Commands/CloseCommand.h"
#include "Commands/DrawBackCommand.h"


OI::OI() {
	// Process operator interface input here.
	controller = ControllerFactory::makeController(DRIVER_CONTROLLER_TYPE,DRIVE_CONTROLLER_PORT);
	preciseMovementButton = new ControllerButton(controller, PRECISE_MOVEMENT_BUTTON);
	preciseMovementButton->WhenPressed(new PreciseArcadeDriveCommand());

	fireButton = new ControllerButton(controller, FIRE_BUTTON);
	fireButton->WhenPressed(new FireCommand());

	openButton = new ControllerButton(controller, OPEN_BUTTON);
	openButton->WhenPressed(new OpenCommand());

	closeButton = new ControllerButton(controller, CLOSE_BUTTON);
	closeButton->WhenPressed(new CloseCommand());
	
	drawBackButton = new ControllerButton(controller, DRAW_BACK_BUTTON);
	drawBackButton->WhenPressed(new DrawBackCommand());
}

OI::~OI() {
	delete controller;
	delete preciseMovementButton;
	delete fireButton;
}

GenericController* OI::getController() {
	return controller;
}
