#include "PickupWatcherCommand.h"

#include "AutomaticPickupCommand.h"

PickupWatcherCommand::PickupWatcherCommand() {
	automaticPickupCommand = new AutomaticPickupCommand();
}

void PickupWatcherCommand::Initialize() {
}

void PickupWatcherCommand::Execute() {

	// Don't respond if the ball was in front of the sensor from the start
	if (wasUp && pickup->isDown())
	{
		shouldPickup = ! pickup->seesBall();
	}

	// If we lose sight of the ball, then it can be picked up if seen again
	if ( ! shouldPickup && pickup->isDown() && ! pickup->seesBall())
	{
		shouldPickup = true;
	}

	// Grab the ball if possible and allowed
	if (shouldPickup && pickup->isDown() && pickup->seesBall())
	{
		automaticPickupCommand->Start();
	}

	wasUp = ! pickup->isDown();
}

bool PickupWatcherCommand::IsFinished() {
	return false;
}

void PickupWatcherCommand::End() {
}

void PickupWatcherCommand::Interrupted() {
}


