#include "StallMotorCommand.h"

StallMotorCommand::StallMotorCommand() : DefaultCommand("StallMotorCommand")
{
	Requires(drivetrain);
}

void StallMotorCommand::Initialize()
{
	drivetrain->setEncoderTargetPositions(drivetrain->getEncoderPositions());
}
