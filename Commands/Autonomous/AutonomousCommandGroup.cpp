#include "AutonomousCommandGroup.h"
#include "../SafePickUpBallCommand.h"
#include "../SafePassBallCommand.h"
#include "../ToggleArmPositionCommand.h"
#include "DriveTimedCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new SafePickUpBallCommand()); //on motor
	AddParallel(new ToggleArmPositionCommand());//move arms out
	AddSequential(new DriveTimedCommand(.4,5));//drive forward
	AddSequential(new SafePassBallCommand());//spit out ball
	//CELEBRATE!
}

