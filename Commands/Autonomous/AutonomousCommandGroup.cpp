#include "AutonomousCommandGroup.h"
#include "CloseTinesCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new CloseTinesCommand());
}

