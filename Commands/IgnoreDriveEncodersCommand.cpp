#include "IgnoreDriveEncodersCommand.h"

IgnoreDriveEncodersCommand::IgnoreDriveEncodersCommand()
	: DefaultCommand("IgnoreDriveEncoders") {}

void IgnoreDriveEncodersCommand::Initialize()
{
	drivetrain->ignoreEncoders();
}

void IgnoreDriveEncodersCommand::End()
{
	drivetrain->useEncoders();
}