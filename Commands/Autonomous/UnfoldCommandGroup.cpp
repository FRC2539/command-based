#include "UnfoldCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../SetShooterHeightCommand.h"

#include "../../Config.h"

UnfoldCommandGroup::UnfoldCommandGroup() : CommandGroup("Unfold")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
}

