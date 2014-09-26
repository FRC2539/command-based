#include "SafePickUpBallCommand.h"

#include "PickUpBallCommand.h"

SafePickUpBallCommand::SafePickUpBallCommand() : ConditionalCommand("SafePickUpBall")
{
	m_command = new PickUpBallCommand();
}

bool SafePickUpBallCommand::shouldRun()
{
	// Don't pick up a ball if we already have one
	return !pickuparm->hasBall();
}


