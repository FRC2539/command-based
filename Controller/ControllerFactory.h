#ifndef CONTROLLER_FACTORY_H
#define CONTROLLER_FACTORY_H

#include "LogitechAttack3Joystick.h"
#include "LogitechCrossfireController.h"
#include "LogitechDualShockController.h"

class ControllerFactory
{
public:
	static GenericController* makeController(std::string type, int port);
};

#endif
