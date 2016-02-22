#include "CrossToCourtyardCommandGroup.h"

#include "AlignmentTurnCommand.h"
#include "CrossDefenseCommand.h"

CrossToCourtyardCommandGroup::CrossToCourtyardCommandGroup()
	: CommandGroup("CrossToCourtyard")
{
	AddSequential(new AlignmentTurnCommand(0));
	AddSequential(new CrossDefenseCommand());
}
