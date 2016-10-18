#include "ReachDefenseCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "DriveToDefenseCommand.h"
#include "../StallMotorCommand.h"

ReachDefenseCommandGroup::ReachDefenseCommandGroup() : CommandGroup("ReachDefense")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new DriveToDefenseCommand());
	AddSequential(new StallMotorCommand());
	
}
