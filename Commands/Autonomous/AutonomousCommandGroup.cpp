#include "AutonomousCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../GraphEncodersCommand.h"
#include "ChangeSpeedCommand.h"
#include "ManualDriveCommand.h"
#include <Commands/WaitCommand.h>
#include "CancelCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
	AddSequential(new AssumeStartingConfigCommand());
}
