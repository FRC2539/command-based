#include "ManualDriveCommand.h"

void ManualDriveCommand::Execute()
{
	drivetrain->move(0, 1, 0);
}

void ManualDriveCommand::End()
{
	drivetrain->move(0, 0, 0);
}
