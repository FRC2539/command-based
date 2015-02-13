#include "OI.h"

#include "Controller/ControllerAxis.h"
#include "Controller/DummyControllerAxis.h"
#include "Controller/ControllerButton.h"

#include "Controller/LogitechAttack3Joystick.h"
#include "Controller/LogitechCrossfireController.h"
#include "Controller/LogitechDualShockController.h"

#include "ControllerLayouts/ControllerLayoutMacros.h"

// Available Commands for ControllerMap
#include "Commands/PreciseDriveCommand.h"
#include "Commands/ResetCommand.h"
#include "Commands/ButtonDriveCommand.h"
#include "Commands/ZeroGyroCommand.h"
#include "Commands/LowerElevatorCommand.h"
#include "Commands/RaiseElevatorCommand.h"

OI::OI()
{
	for (int i = 0; i < logicalAxes::NumOfAxes; i++)
	{
		axes[i] = new DummyControllerAxis();
	}

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
		delete axis;
	}

	for (auto controller : controllers)
	{
		delete controller;
	}
}

float OI::getAxisValue(const int axis)
{
	return axes[axis]->getValue();
}

