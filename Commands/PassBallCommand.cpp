#include "PassBallCommand.h"

#include "../RobotMap.h" 

PassBallCommand::PassBallCommand() : DefaultCommand("PassBall")
{
	Requires(pickuparm);
}

void PassBallCommand::Initialize()
{
	pickuparm->setWheelSpeed(-RobotMap::PickUpArm::pickUpSpeed);
}

bool PassBallCommand::IsFinished()
{
    return !pickuparm->hasBall();
}

void PassBallCommand::End()
{
    pickuparm->setWheelSpeed(0);
}
