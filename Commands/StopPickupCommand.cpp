#include "StopPickupCommand.h"

StopPickupCommand::StopPickupCommand() : InstantCommand("StopPickup")
{
	Requires(pickuparms);
	Requires(shooter);
}

void StopPickupCommand::Initialize()
{
	pickuparms->setRollerSpeed(0);
	shooter->stopShooter();
	shooter->setIndexerSpeed(0);
}
