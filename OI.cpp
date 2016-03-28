#include "OI.h"

#include "Config.h"

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
#include "Commands/SetShooterHeightCommand.h"
#include "Commands/LowGoalCommand.h"
#include "Commands/PickupCommand.h"
#include "Commands/CollectBoulderCommand.h"


OI::OI()
{
	for (int i = 0; i < logicalAxes::NumOfAxes; i++)
	{
		axes[i] = new DummyControllerAxis();
	}

	Command* lastCommand;
	int buttonIntValue;

	/* This injects the current controller layout into the OI class. Due to
	 * this, the controller layouts are not standalone, and will have parsing
	 * errors because information they need is coming from this class, which
	 * they know nothing about.
	 */
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

