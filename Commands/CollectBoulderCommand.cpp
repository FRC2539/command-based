#include "CollectBoulderCommand.h"

#include "../Config.h"

CollectBoulderCommand::CollectBoulderCommand() :
	DefaultCommand("CollectBoulder")
{
	Requires(shooter);
	Requires(pickuparms);
}

void CollectBoulderCommand::Initialize()
{
	pickuparms->setRollerSpeed(-0.3);
	shooter->setShooterSpeed(-200);
	shooter->setIndexerSpeed(-0.3);
}

bool CollectBoulderCommand::IsFinished()
{
    return shooter->hasBall();
}

void CollectBoulderCommand::End()
{
    pickuparms->setRollerSpeed(0);
	shooter->stopShooter();
	shooter->setIndexerSpeed(0);
}
