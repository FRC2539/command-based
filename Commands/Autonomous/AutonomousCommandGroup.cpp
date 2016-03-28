#include "AutonomousCommandGroup.h"

#include "AssumeStartingConfigCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new AssumeStartingConfigCommand());
}

