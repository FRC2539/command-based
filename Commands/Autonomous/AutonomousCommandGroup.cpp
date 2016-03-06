#include "AutonomousCommandGroup.h"

#include "../ZeroGyroCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddParallel(new ZeroGyroCommand());
}

