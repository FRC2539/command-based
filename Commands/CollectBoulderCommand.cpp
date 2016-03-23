#include "CollectBoulderCommand.h"

CollectBoulderCommand::CollectBoulderCommand() :
	DefaultCommand("CollectBoulder")
{
	Requires(shooter);
}

void CollectBoulderCommand::Initialize()
{
	shooter->setShooterSpeed(-200);
	shooter->setIndexerSpeed(-0.3);
}

bool CollectBoulderCommand::IsFinished()
{
    return shooter->hasBall();
}
