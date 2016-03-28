#include "CrossDefenseCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommand.h"

CrossDefenseCommandGroup::CrossDefenseCommandGroup() : CommandGroup("CrossDefense")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new CrossDefenseCommand());
	AddSequential(new DriveDistanceCommand(24));
}
