#include "PassBallCommand.h"

#include "../RobotMap.h" 

PassBallCommand::PassBallCommand() : DefaultCommand("PassBall")
{
	Requires(pickuparm);
}

void PassBallCommand::Initialize()
{
	ballReleased = false;
	pickuparm->setWheelSpeed(-RobotMap::PickUpArm::pickUpSpeed);
}

bool PassBallCommand::IsFinished()
{
	if (ballReleased == false)
	{
		if (!pickuparm->hasBall())
		{
			SetTimeout(
				TimeSinceInitialized() + RobotMap::PickUpArm::passTimeout
			);
			ballReleased = true;
		}

		return false;
	}

	return IsTimedOut();
}

void PassBallCommand::End()
{
	pickuparm->setWheelSpeed(0);
}
