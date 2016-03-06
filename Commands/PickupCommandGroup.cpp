#include "PickupCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SetPickupArmsHeightCommand.h"
#include "CollectBoulderCommand.h"
#include <Commands/WaitCommand.h>
#include "StopPickupCommand.h"
#include "SetShooterHeightDownCommandGroup.h"

PickupCommandGroup::PickupCommandGroup() : CommandGroup("Pickup")
{
	//AddParallel(new SetPickupArmsHeightCommand(Config::PickupArms::minHeight));
	//AddSequential(new WaitCommand(.7));
	AddParallel(new SetShooterHeightDownCommandGroup());
	//AddParallel(new SetPickupArmsHeightCommand(Config::PickupArms::maxHeight));
	AddSequential(new CollectBoulderCommand());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new StopPickupCommand());
}

