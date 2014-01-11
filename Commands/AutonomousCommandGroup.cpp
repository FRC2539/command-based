#include "AutonomousCommandGroup.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential(new RunMotorCommand(1));
	AddSequential(new RunTalonCommand(-1));
	AddSequential(new WaitCommand(2));
	AddSequential(new StopMotorCommand());
	AddSequential(new StopTalonCommand());
	AddSequential(new WaitCommand(2));
	AddSequential(new RunMotorCommand(-1));
	AddSequential(new RunTalonCommand(1));
	AddSequential(new WaitCommand(2));
	AddSequential(new StopMotorCommand());
	AddSequential(new StopTalonCommand());
}


