#include "FireCommandGroup.h"

#include "../Config.h"

#include <Commands/WaitCommand.h>
//#include "FaceGoalCommand.h"
//#include "MoveToRangeCommand.h"
#include "PrepareToLaunchCommandGroup.h"
#include "LaunchBoulderCommand.h"
#include "SetShooterHeightCommand.h"

FireCommandGroup::FireCommandGroup() : CommandGroup("Fire")
{
	//AddSequential(new FaceGoalCommand());
	//AddSequential(new WaitCommand(0.25));
	//AddSequential(new MoveToRangeCommand());
	//AddSequential(new WaitCommand(0.25));
	//AddSequential(new FaceGoalCommand());
	AddParallel(new PrepareToLaunchCommandGroup());
	AddSequential(new WaitCommand(2));
	AddSequential(new LaunchBoulderCommand());
	//AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
}

