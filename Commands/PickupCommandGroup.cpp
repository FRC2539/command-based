#include "PickupCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SetPickupArmsHeightCommand.h"
#include "CollectBoulderCommand.h"
#include <Commands/WaitCommand.h>
#include "StopPickupCommand.h"

PickupCommandGroup::PickupCommandGroup() : CommandGroup("Pickup")
{
	AddSequential(new SetPickupArmsHeightCommand(Config::PickupArms::ballRollerHeight));
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
	AddSequential(new CollectBoulderCommand());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new StopPickupCommand());
	AddSequential(new SetPickupArmsHeightCommand(Config::PickupArms::maxHeight));
}

