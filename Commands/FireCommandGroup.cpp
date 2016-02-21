#include "FireCommandGroup.h"

#include <Commands/WaitCommand.h>
//#include "FaceGoalCommand.h"
//#include "MoveToRangeCommand.h"
#include "PrepareToLaunchCommandGroup.h"
#include "LaunchBoulderCommand.h"

FireCommandGroup::FireCommandGroup() : CommandGroup("Fire")
{
	//AddSequential(new FaceGoalCommand());
	AddSequential(new WaitCommand(0.25));
	//AddSequential(new MoveToRangeCommand());
	AddSequential(new WaitCommand(0.25));
	//AddSequential(new FaceGoalCommand());
	AddSequential(new PrepareToLaunchCommandGroup());
	AddSequential(new LaunchBoulderCommand());
}

