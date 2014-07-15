#include "ControllerFactory.h"

GenericController* ControllerFactory::makeController(std::string type, int port)
{
	if(type == "LogitechAttack3")
	{
		return new LogitechAttack3Joystick(port);
	}
	else if(type == "LogitechCrossfire")
	{
		return new LogitechCrossfireController(port);
	}
	else if(type == "LogitechDualShock")
	{
		return new LogitechDualShockController(port);
	}
	// throw Exception;

	return NULL;
}
