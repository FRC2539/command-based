#include "CollectBoulderCommand.h"

CollectBoulderCommand::CollectBoulderCommand() :
	DefaultCommand("CollectBoulder")
{
	Requires(shooter);
}

void CollectBoulderCommand::Initialize()
{
	shooter->setShooterSpeed(-80);
	shooter->setIndexerSpeed(-0.45);
}

bool CollectBoulderCommand::IsFinished()
{
    return shooter->hasBall();
}
