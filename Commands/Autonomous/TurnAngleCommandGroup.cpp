#include "TurnAngleCommandGroup.h"

#include "CalculateAngleCommand.h"
#include "ApproachAngleCommand.h"
#include "StopAtPositionCommand.h"
#include <Commands/WaitCommand.h>

TurnAngleCommandGroup::TurnAngleCommandGroup(float angle)
	: CommandGroup("TurnAngle")
{
	AddSequential(new CalculateAngleCommand(angle));
	AddSequential(new ApproachAngleCommand(angle));
	AddSequential(new WaitCommand(0.25));
	AddSequential(new StopAtPositionCommand());
}
