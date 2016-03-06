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
	//pickuparms->setRollerSpeed(-0.6);
	shooter->setShooterSpeed(-.5);
	shooter->setIndexerSpeed(-0.15);
}

bool CollectBoulderCommand::IsFinished()
{
    return shooter->hasBall();
}
