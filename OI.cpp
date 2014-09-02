#include "OI.h"

#include "Controller/ControllerAxis.h"
#include "Controller/ControllerButton.h"

#include "Controller/LogitechAttack3Joystick.h"
#include "Controller/LogitechCrossfireController.h"
#include "Controller/LogitechDualShockController.h"
#include "Controller/AndroidDriverStation.h"

#include "Commands/Types/ToggleCommand.h"

// Available Commands for ControllerMap
#include "Commands/PreciseArcadeDriveCommand.h"
#include "Commands/ResetCommand.h"

OI::OI()
{
	ControllerAxis* lastAxis;

	#include "ControllerMap.h"
}

OI::~OI()
{
	for (auto button : buttons)
	{
		delete button;
	}

	for (auto values : axes)
	{
		for (auto axis : values.second)
		{
			delete axis;
		}
	}

	for (auto controller : controllers)
	{
		delete controller.second;
	}
}

std::vector<float> OI::getAxes(std::string system)
{
	std::vector<float> values;

	for (auto axis : axes[system])
	{
		values.push_back(axis->getValue());
	}

	return values;
}

