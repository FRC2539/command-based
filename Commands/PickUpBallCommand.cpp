#include "PickUpBallCommand.h"

#include "../RobotMap.h" 

PickUpBallCommand::PickUpBallCommand() : DefaultCommand("PickUpBall")
{
	Requires(pickuparm);
}

void PickUpBallCommand::Initialize()
{
	ballLoaded = false;
	pickuparm->setWheelSpeed(RobotMap::PickUpArm::pickUpSpeed);
}

bool PickUpBallCommand::IsFinished()
{
	if (ballLoaded == false)
	{
		if (!pickuparm->hasBall())
		{
			SetTimeout(
				TimeSinceInitialized() + RobotMap::PickUpArm::pickUpTimeout
			);
			ballLoaded = true;
		}

		return false;
	}

	return IsTimedOut();
}

void PickUpBallCommand::End()
{
	pickuparm->setWheelSpeed(0);
}
