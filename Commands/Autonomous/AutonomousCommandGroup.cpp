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
	AddSequential(new SetTinesCommand(22));
	AddSequential(new SetElevatorCommand(4655));
 	AddSequential(new DriveDistanceCommand(22, DriveDistanceCommand::Y));
	AddSequential(new SetElevatorCommand(4100));
 	AddSequential(new DriveDistanceCommand(-6, DriveDistanceCommand::Y));
	AddSequential(new SetElevatorCommand(0));
 	AddSequential(new DriveDistanceCommand(2, DriveDistanceCommand::Y));
	AddSequential(new SetTinesCommand(16));
	AddSequential(new SetElevatorCommand(500));
	AddSequential(new TurnAngleCommand(85)); 
	AddSequential(new DriveDistanceCommand(115, DriveDistanceCommand::Y));

}
