#include "AutonomousCommandGroup.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	int count = 5;
	int i = 0;
	while (i < count)
	{
		AddSequential(new RunMotorCommand(1));
		AddSequential(new RunTalonCommand(.5));
		AddSequential(new WaitCommand(.5));
		AddSequential(new RunMotorCommand(-1));
		AddSequential(new RunTalonCommand(-.5));
		AddSequential(new WaitCommand(.5));

		i++;
	}

	AddSequential(new StopMotorCommand());
	AddSequential(new StopTalonCommand());
}


