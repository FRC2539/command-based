#include "AutonomousCommandGroup.h"
#include <Commands/WaitCommand.h>

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential(new RunTalonCommand(.5));
	AddSequential(new WaitCommand(2));
	AddSequential(new StopTalonCommand());
}


