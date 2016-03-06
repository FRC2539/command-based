#include "LaunchBoulderCommand.h"

LaunchBoulderCommand::LaunchBoulderCommand() :
	TimedCommand("LaunchBoulder", 1)
{
	Requires(shooter);
}

void LaunchBoulderCommand::Initialize()
{
	shooter->setIndexerSpeed(.3);
	shooter->setShooterSpeed(1);
}

void LaunchBoulderCommand::End()
{
	shooter->setIndexerSpeed(0);
	shooter->stopShooter();
}




