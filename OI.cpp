#include "OI.h"

OI::OI() {
	// Process operator interface input here.
	controller = new Joystick(CONTROLLER_PORT);
}

OI::~OI() {
	delete controller;
}


Joystick* OI::getController() {
	return controller;
}

