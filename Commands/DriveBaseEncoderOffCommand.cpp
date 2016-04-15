#include "DriveBaseEncoderOffCommand.h"

DriveBaseEncoderOffCommand::DriveBaseEncoderOffCommand()
	: DefaultCommand("Drive Base Encoder Off")
{
}

void DriveBaseEncoderOffCommand::Initialize()
{
	drivetrain->ignoreEncoders();
}
