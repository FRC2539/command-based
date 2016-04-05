#include "LowBarCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../ShooterMoveCommand.h"
#include "../SetShooterHeightCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommand.h"

#include "../../Config.h"

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new ShooterMoveCommand(Shooter::DOWN));
	AddSequential(new CrossDefenseCommand());
	AddSequential(new DriveDistanceCommand(24));
}

