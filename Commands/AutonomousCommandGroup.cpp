#include "AutonomousCommandGroup.h"
#include "RunMotorCommand.h"
#include "StopMotorCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential(new RunMotorCommand(.2));
	AddSequential(new WaitCommand(5));
	AddSequential(new StopMotorCommand());
}
