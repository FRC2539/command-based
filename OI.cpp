#include "OI.h"

#define CONTROLLER_PORT 3

OI::OI() : controller(CONTROLLER_PORT) {
	// Process operator interface input here.
}

float OI::GetControllerAxis(int axis){

	return controller.GetRawAxis(axis);
}