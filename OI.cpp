#include "OI.h"
#include "Controller/LogitechAttack3Joystick.h"

OI::OI() {
	// Process operator interface input here.
	controller = new LogitechAttack3Joystick(DRIVE_CONTROLLER_PORT);
}

OI::~OI() {
	delete controller;
}


Joystick* OI::getController() {
	return controller;
}

