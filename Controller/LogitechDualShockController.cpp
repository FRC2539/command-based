#include "LogitechDualShockController.h"

CONTROLLER_SETUP(LogitechDualShockController)

void LogitechDualShockController::init()
{
	invertedAxes = {LeftY, RightY, DPadY};
}
