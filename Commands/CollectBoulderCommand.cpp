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
	pickuparms->setRollerSpeed(-0.4);
	shooter->setShooterSpeed(-.4);
	shooter->setIndexerSpeed(-0.15);
}

bool CollectBoulderCommand::IsFinished()
{
    return shooter->hasBall();
}
