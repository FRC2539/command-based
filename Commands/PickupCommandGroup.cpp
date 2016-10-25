#include "PickupCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "CollectBoulderCommand.h"
#include <Commands/WaitCommand.h>
#include "StopPickupCommand.h"

PickupCommandGroup::PickupCommandGroup() : CommandGroup("Pickup")
{
	//AddParallel(new SetShooterHeightCommand(Config::Shooter::minHeight));
	AddSequential(new CollectBoulderCommand());
	AddSequential(new WaitCommand(4));
	AddSequential(new StopPickupCommand());
}

