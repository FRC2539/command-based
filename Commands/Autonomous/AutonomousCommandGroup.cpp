#include "AutonomousCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../SetDriveTrainMaxSpeedCommand.h"
#include "../DriveBaseEncoderOffCommand.h"
#include "ManualDriveCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup() : CommandGroup("Autonomous")
{
//	AddSequential(new AssumeStartingConfigCommand());
//	AddSequential(new DriveBaseEncoderOffCommand());
	AddSequential(new SetDriveTrainMaxSpeedCommand(150));
	AddSequential(new ManualDriveCommand(10s));
}

