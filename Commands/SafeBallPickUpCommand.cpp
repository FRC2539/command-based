#include "SafeBallPickUpCommand.h"

#include "PickUpBallCommand.h"

SafeBallPickUpCommand::SafeBallPickUpCommand() : ConditionalCommand("SafeBallPickUp")
{
	m_command = new PickUpBallCommand();
}

bool SafeBallPickUpCommand::shouldRun()
{
	return !pickuparm->hasBall();
}


