#include "DriveCommand.h"

DriveCommand::DriveCommand() : DefaultCommand("Drive")
{
	Requires(drivetrain);
}

void DriveCommand::Execute()
{
	drivetrain->MOVE_WITH_JOYSTICK;
}

