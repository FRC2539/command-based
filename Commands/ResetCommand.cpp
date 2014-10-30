#include "ResetCommand.h"
#include <DoubleSolenoid.h>

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(pickuparm);
}

void ResetCommand::Initialize()
{
	drivetrain->directDrive(0, 0);
	pickuparm->setWheelSpeed(0);
	pickuparm->setArmPosition(DoubleSolenoid::kOff);
}


