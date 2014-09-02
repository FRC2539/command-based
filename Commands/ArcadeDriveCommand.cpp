#include "ArcadeDriveCommand.h"

ArcadeDriveCommand::ArcadeDriveCommand() : DefaultCommand("ArcadeDrive")
{
	Requires(drivetrain);
}

void ArcadeDriveCommand::Execute()
{
	drivetrain->move(oi->getAxes("TwoAxisDrive"));
}

