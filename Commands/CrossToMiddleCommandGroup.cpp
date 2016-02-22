#include "CrossToMiddleCommandGroup.h"

#include "AlignmentTurnCommand.h"
#include "CrossDefenseCommand.h"

CrossToMiddleCommandGroup::CrossToMiddleCommandGroup()
	: CommandGroup("CrossToMiddle")
{
	AddSequential(new AlignmentTurnCommand(180));
	AddSequential(new CrossDefenseCommand());
}
