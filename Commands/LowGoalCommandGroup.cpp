#include "LowGoalCommandGroup.h"

#include "PrepareToBowlCommandGroup.h"
#include "LaunchBoulderCommand.h"

LowGoalCommandGroup::LowGoalCommandGroup() : CommandGroup("LowGoal")
{
	AddSequential(new PrepareToBowlCommandGroup());
	AddSequential(new LaunchBoulderCommand());
}

