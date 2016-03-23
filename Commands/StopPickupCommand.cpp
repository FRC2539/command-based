#include "StopPickupCommand.h"

StopPickupCommand::StopPickupCommand() : InstantCommand("StopPickup")
{
	Requires(shooter);
}

void StopPickupCommand::Initialize()
{
	shooter->stopShooter();
	shooter->setIndexerSpeed(0);
}
