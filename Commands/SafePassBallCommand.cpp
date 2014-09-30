#include "SafePassBallCommand.h"

#include "PassBallCommand.h"

SafePassBallCommand::SafePassBallCommand() : ConditionalCommand("SafePassBall")
{
	m_command = new PassBallCommand();
}

bool SafePassBallCommand::shouldRun()
{
	// Don't pass a ball if we don't have one.
	return pickuparm->hasBall();
}


