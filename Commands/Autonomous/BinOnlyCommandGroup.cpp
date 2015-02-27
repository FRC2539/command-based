#include "BinOnlyCommandGroup.h"

#include "../ResetCommand.h"
#include "SetElevatorCommand.h"
#include "SetTinesCommand.h"
#include "DriveDistanceCommand.h"
#include "TurnAngleCommand.h"

BinOnlyCommandGroup::BinOnlyCommandGroup() : CommandGroup("BinOnly")
{
	AddSequential(new ResetCommand());
	AddSequential(new SetTinesCommand(22));
	AddSequential(new SetElevatorCommand(4655));
	AddSequential(new DriveDistanceCommand(-4, DriveDistanceCommand::Y));
	AddSequential(new TurnAngleCommand(-85));
	AddSequential(new DriveDistanceCommand(115, DriveDistanceCommand::Y, 100));
}
