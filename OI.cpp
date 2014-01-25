#include "OI.h"
#include "Controller/ControllerFactory.h"

OI::OI() {
	// Process operator interface input here.
	controller = ControllerFactory::makeController(DRIVER_CONTROLLER_TYPE,DRIVE_CONTROLLER_PORT);
}

OI::~OI() {
	delete controller;
}

GenericController* OI::getController() {
	return controller;
}

