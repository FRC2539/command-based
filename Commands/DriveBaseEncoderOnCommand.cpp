#include "DriveBaseEncoderOnCommand.h"

DriveBaseEncoderOnCommand::DriveBaseEncoderOnCommand()
	: DefaultCommand("Drive Base Encoder On")
{
}

void DriveBaseEncoderOnCommand::Initialize()
{
	drivetrain->useEncoders();
}

void DriveBaseEncoderOnCommand::End()
{
	drivetrain->ignoreEncoders();
}