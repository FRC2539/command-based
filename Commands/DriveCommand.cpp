#include "DriveCommand.h"

DriveCommand::DriveCommand() : DefaultCommand("Drive")
{
	Requires(drivetrain);
}

void DriveCommand::Execute()
{
	MOVE_WITH_JOYSTICK;
}

