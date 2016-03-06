#include "OI.h"

#include "Controller/ControllerAxis.h"
#include "Controller/DummyControllerAxis.h"
#include "Controller/ControllerButton.h"
#include "Controller/POVButton.h"

#include "Controller/LogitechAttack3Joystick.h"
#include "Controller/LogitechCrossfireController.h"
#include "Controller/LogitechDualShockController.h"

#include "ControllerLayouts/ControllerLayoutMacros.h"

// Available Commands for ControllerMap
#include "Commands/DriveCommand.h"
#include "Commands/ResetCommand.h"
#include "Commands/FixedHeadingCommand.h"
#include "Commands/AlignmentTurnCommand.h"
#include "Commands/MotorTestCommand.h"
#include "Commands/GyroCrossDefenseCommand.h"
#include "Commands/SetShooterHeightUpCommandGroup.h"
#include "Commands/SetPickupArmsHeightCommand.h"
#include "Commands/LowGoalCommand.h"
#include "Commands/PickupCommand.h"
#include "Commands/CollectBoulderCommand.h"
#include "Commands/LaunchBoulderCommand.h"
#include "Commands/PickupCommandGroup.h"
#include "Commands/SetShooterHeightDownCommandGroup.h"
#include "Commands/StopPickupCommand.h"

OI::OI()
{
	for (int i = 0; i < logicalAxes::NumOfAxes; i++)
	{
		axes[i] = new DummyControllerAxis();
	}

	Command* lastCommand;
	int buttonIntValue;

	#include "ControllerMap.h" //THIS VERY IMPORTANT NO REMOVE

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

