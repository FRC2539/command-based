#include "CrossDefenseCommandGroup.h"

#include "CrossDefenseCommand.h"

CrossDefenseCommandGroup::CrossDefenseCommandGroup() : CommandGroup("CrossDefense")
{
	AddSequential(new CrossDefenseCommand());
}