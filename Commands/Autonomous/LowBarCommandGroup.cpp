#include "LowBarCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../ShooterMoveCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommand.h"
#include "ChangeSpeedCommand.h"

#include "../../Config.h"

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
//	AddSequential(new AssumeStartingConfigCommand());
//	AddSequential(new ShooterMoveCommand(Shooter::DOWN));
	AddParallel(new ChangeSpeedCommand(150));
	AddSequential(new CrossDefenseCommand());
//	AddSequential(new DriveDistanceCommand(24));
}

