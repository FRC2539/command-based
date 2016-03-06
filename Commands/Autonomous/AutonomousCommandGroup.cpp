#include "AutonomousCommandGroup.h"

#include "../ZeroGyroCommand.h"
#include "UnfoldCommandGroup.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddParallel(new ZeroGyroCommand());
	//AddSequential(new UnfoldCommandGroup());
}

