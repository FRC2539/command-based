#include "CrossDefenseCommandGroup.h"

#include "FaceDefenseCommand.h"
#include "CrossDefenseCommand.h"

CrossDefenseCommandGroup::CrossDefenseCommandGroup() : CommandGroup("CrossDefense")
{
	AddSequential(new FaceDefenseCommand());
	AddSequential(new CrossDefenseCommand());
}