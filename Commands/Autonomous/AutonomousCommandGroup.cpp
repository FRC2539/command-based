#include "AutonomousCommandGroup.h"
#include "TestTalonCommand.h"


AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new TestTalonCommand());
}

