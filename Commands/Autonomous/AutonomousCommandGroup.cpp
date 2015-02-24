#include "AutonomousCommandGroup.h"

#include "../ResetCommand.h"
#include "CloseTinesCommand.h"
#include "SetElevatorCommand.h"
#include "DriveDistanceCommand.h"
#include "SetTinesCommand.h"
#include "TurnAngleCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new ResetCommand());
	//AddSequential(new SetTinesCommand(22));
	//AddSequential(new SetElevatorCommand(4655));
	AddSequential(new DriveDistanceCommand(22, DriveDistanceCommand::Y));
	//AddSequential(new SetElevatorCommand(4250));
	//AddSequential(new SetTinesCommand(25));
	AddSequential(new DriveDistanceCommand(-10, DriveDistanceCommand::Y));
	//AddSequential(new SetElevatorCommand(0));
	//AddSequential(new CloseTinesCommand());
	//AddSequential(new SetElevatorCommand(375));
	//AddSequential(new TurnAngleCommand(-90));
	//AddSequential(new DriveDistanceCommand(40, DriveDistanceCommand::Y));

}

