#include "CrossDefenseCommandGroup.h"

#include "AutoDefenseTraverse180.h"
#include "AutoDefenseTraverseZero.h"
#include "CrossDefenseCommand.h"

CrossDefenseCommandGroup::CrossDefenseCommandGroup() : CommandGroup("CrossDefense")
{
	AddSequential(new AutoDefenseTraverseZero());
	AddSequential(new AutoDefenseTraverse180());
	AddSequential(new CrossDefenseCommand());
}