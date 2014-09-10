#include "OI.h"

#include "Controller/ControllerAxis.h"
#include "Controller/ControllerButton.h"

#include "Controller/LogitechAttack3Joystick.h"
#include "Controller/LogitechCrossfireController.h"
#include "Controller/LogitechDualShockController.h"
#include "Controller/AndroidDriverStation.h"

#include "ControllerLayouts/ControllerLayoutMacros.h"

#include "Commands/Types/ToggleCommand.h"

// Available Commands for ControllerMap
#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/ResetCommand.h"

OI::OI()
{
	Command* lastCommand;

	#include "ControllerMap.h"
}

OI::~OI()
{
	for (auto button : buttons)
	{
		delete button;
	}

	for (auto axis : axes)
	{
		delete axis.second;
	}

	for (auto controller : controllers)
	{
		delete controller.second;
	}
}

float OI::getAxisValue(const char* axisName)
{
	if (axes.count(axisName) == 0)
	{
		return 0;
	}
	return axes[axisName]->getValue();
}

