#include "LogitechAttack3Joystick.h"
#include "LogitechCrossfireController.h"
#include "LogitechDualShockController.h"

class ControllerFactory
{
public:
	static GenericController* makeController(std::string type, int port);
};
