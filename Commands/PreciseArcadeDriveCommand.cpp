#include "PreciseArcadeDriveCommand.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand()
	: DefaultCommand("PreciseArcadeDrive")
{
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Execute()
{
	drivetrain->preciseMove(oi->getAxes("TwoAxisDrive"));
}