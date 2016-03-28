#include "LowBarCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../SetShooterHeightCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommand.h"

#include "../../Config.h"

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
	AddSequential(new CrossDefenseCommand());
	AddSequential(new DriveDistanceCommand(24));
}

