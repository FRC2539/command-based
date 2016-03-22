#include "UnfoldCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../SetPickupArmsHeightCommand.h"
#include "../SetShooterHeightCommand.h"

#include "../../Config.h"

UnfoldCommandGroup::UnfoldCommandGroup() : CommandGroup("Unfold")
{
	AddSequential(new AssumeStartingConfigCommand());
	AddSequential(new SetPickupArmsHeightCommand(Config::PickupArms::minHeight));
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
}

