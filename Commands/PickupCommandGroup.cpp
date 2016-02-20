#include "PickupCommandGroup.h"

//#include "PrepareToPickupCommandGroup.h"
//#include "CollectBoulderCommand.h"

PickupCommandGroup::PickupCommandGroup() : CommandGroup("Pickup")
{
	//AddSequential(new PrepareToPickupCommandGroup());
	//AddSequential(new CollectBoulderCommand());
}

