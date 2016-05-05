#include "DriveBaseEncoderOffCommand.h"

DriveBaseEncoderOffCommand::DriveBaseEncoderOffCommand()
	: InstantCommand("Drive Base Encoder Off")
{
}

void DriveBaseEncoderOffCommand::Initialize()
{
	drivetrain->ignoreEncoders();
}
