#include "PickUpBallCommand.h"

#include "../RobotMap.h" 

PickUpBallCommand::PickUpBallCommand() : DefaultCommand("PickUpBall")
{
	Requires(pickuparm);
}

void PickUpBallCommand::Initialize()
{
	pickuparm->setWheelSpeed(RobotMap::PickUpArm::pickUpSpeed);
}

bool PickUpBallCommand::IsFinished()
{
	return pickuparm->hasBall();
}

void PickUpBallCommand::End()
{
	pickuparm->setWheelSpeed(0);
}
