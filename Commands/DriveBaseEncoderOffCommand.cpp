#include "DriveBaseEncoderOffCommand.h"

DriveBaseEncoderOffCommand::DriveBaseEncoderOffCommand()
	: DefaultCommand("Drive Base Encoder Off")
{
}

void DriveBaseEncoderOffCommand::Initialize()
{
	drivetrain->ignoreEncoders();
}

void DriveBaseEncoderOffCommand::End()
{
	drivetrain->useEncoders();
}