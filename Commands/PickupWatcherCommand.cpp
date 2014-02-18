#include "PickupWatcherCommand.h"

#include "AutomaticPickupCommand.h"

PickupWatcherCommand::PickupWatcherCommand() {
	automaticPickupCommand = new AutomaticPickupCommand();
}

void PickupWatcherCommand::Initialize() {
	shouldPickup = true;
	wasNotDown = ! pickup->isDown();
}

void PickupWatcherCommand::Execute() {

	if (pickup->isDown())
	{
		// Don't respond if the ball was in front of the sensor from the start
		if (wasNotDown)
		{
			shouldPickup = ! pickup->seesBall();
			wasNotDown = false;
		}

		// Grab the ball if it is in range and was not already held
		else if (shouldPickup && pickup->seesBall())
		{
			automaticPickupCommand->Start();
			shouldPickup = false;
		}

		// If we lose sight of the ball, then it can be picked up if seen again
		else if ( ! shouldPickup && ! pickup->seesBall())
		{
			shouldPickup = true;
		}
	}
	else
	{
		wasNotDown = true;
	}
}

bool PickupWatcherCommand::IsFinished() {
	return false;
}

void PickupWatcherCommand::End() {
}

void PickupWatcherCommand::Interrupted() {
}


