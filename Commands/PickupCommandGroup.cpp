#include "PickupCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SetPickupArmsHeightCommand.h"
#include "CollectBoulderCommand.h"

PickupCommandGroup::PickupCommandGroup() : CommandGroup("Pickup")
{
	AddSequential(new SetPickupArmsHeightCommand(Config::PickupArms::ballRollerHeight));
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
	AddSequential(new CollectBoulderCommand());
}

