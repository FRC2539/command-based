#include "AutonomousCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "ChangeSpeedCommand.h"
#include "ManualDriveCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new ChangeSpeedCommand(150));
	AddSequential(new ManualDriveCommand(10s));
}

