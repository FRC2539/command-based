#include "AutonomousCommandGroup.h"
#include <Commands/WaitCommand.h>

AutonomousCommandGroup::AutonomousCommandGroup() {
	int start = 0;
	while (start < 20)
	{
		AddSequential(new RunMotorCommand(-1));
		AddSequential(new WaitCommand(.1));
		AddSequential(new StopMotorCommand());
		AddSequential(new WaitCommand(.1));

		start++;
	}
	AddSequential(new RunTalonCommand(.5));
	AddSequential(new WaitCommand(.5));
	AddSequential(new StopTalonCommand());
}


