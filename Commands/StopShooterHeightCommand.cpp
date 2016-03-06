#include "StopShooterHeightCommand.h"

StopShooterHeightCommand::StopShooterHeightCommand() :
	DefaultCommand("StopShooterHeight")
{
	Requires(shooter);
}

void StopShooterHeightCommand::Initialize()
{
	shooter->pivotToHeight(0);
}
