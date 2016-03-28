#include "ReachDefenseCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "DriveToDefenseCommand.h"

ReachDefenseCommandGroup::ReachDefenseCommandGroup() : CommandGroup("ReachDefense")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new DriveToDefenseCommand());
}
