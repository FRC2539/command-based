#include "CrossDefenseCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommandGroup.h"

CrossDefenseCommandGroup::CrossDefenseCommandGroup() : CommandGroup("CrossDefense")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new CrossDefenseCommand());
	AddSequential(new DriveDistanceCommandGroup(24));
}
