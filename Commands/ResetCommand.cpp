#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(shooter);
}

void ResetCommand::Initialize()
{
	drivetrain->stop();
	shooter->stopShooter();
	shooter->setIndexerSpeed(0);
}


