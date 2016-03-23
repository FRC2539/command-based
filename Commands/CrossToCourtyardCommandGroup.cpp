#include "CrossToCourtyardCommandGroup.h"

#include "AlignmentTurnCommand.h"
#include "CrossDefenseCommand.h"

CrossToCourtyardCommandGroup::CrossToCourtyardCommandGroup()
	: CommandGroup("CrossToCourtyard")
{
	AddSequential(new AlignmentTurnCommand(180));
	AddSequential(new CrossDefenseCommand());
}
