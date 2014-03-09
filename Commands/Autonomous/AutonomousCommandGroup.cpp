#include "AutonomousCommandGroup.h"
#include "PrepareToShootCommandGroup.h"
#include "../FireCommandGroup.h"


AutonomousCommandGroup::AutonomousCommandGroup()
	: CommandGroup("Autonomous")
{
	AddSequential(new PrepareToShootCommandGroup());
	AddSequential(new FireCommandGroup());
}

