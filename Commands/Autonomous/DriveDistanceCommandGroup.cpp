#include "DriveDistanceCommandGroup.h"

#include "CalculatePositionsCommand.h"
#include "ApproachPositionCommand.h"
#include "StopAtPositionCommand.h"
#include <Commands/WaitCommand.h>

DriveDistanceCommandGroup::DriveDistanceCommandGroup(float distance)
	: CommandGroup("DriveDistance")
{
	AddSequential(new CalculatePositionsCommand(distance));
	AddSequential(new ApproachPositionCommand(distance));
	AddSequential(new WaitCommand(0.25));
	AddSequential(new StopAtPositionCommand());
}
