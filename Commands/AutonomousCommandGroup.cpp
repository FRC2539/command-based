#include "AutonomousCommandGroup.h"
#include "RunMotorCommand.h"
#include "StopMotorCommand.h"
#include "RunTalonCommand.h"
#include "StopTalonCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential(new RunMotorCommand(1));
	AddSequential(new RunTalonCommand(1));
	AddSequential(new WaitCommand(7));
	AddSequential(new RunMotorCommand(.5));
	AddSequential(new RunTalonCommand(.5));
	AddSequential(new WaitCommand(5));
	AddSequential(new StopMotorCommand());
	AddSequential(new StopTalonCommand());
}


