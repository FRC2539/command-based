#include "LowGoalCommandGroup.h"

#include "PrepareToBowlCommandGroup.h"
#include "LaunchBoulderCommand.h"

LowGoalCommandGroup::LowGoalCommandGroup() : CommandGroup("LowGoal")
{
	AddParallel(new PrepareToBowlCommandGroup());
	AddSequential(new WaitCommand(1.3));
	AddSequential(new LaunchBoulderCommand());
}

