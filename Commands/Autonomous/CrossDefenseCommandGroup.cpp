#include "CrossDefenseCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommandGroup.h"
#include <Commands/WaitCommand.h>

CrossDefenseCommandGroup::CrossDefenseCommandGroup() : CommandGroup("CrossDefense")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new CrossDefenseCommand());
	AddSequential(new WaitCommand(2.0));
	AddSequential(new DriveDistanceCommandGroup(24));
}
