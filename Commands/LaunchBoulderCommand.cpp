#include "LaunchBoulderCommand.h"

LaunchBoulderCommand::LaunchBoulderCommand() :
	TimedCommand("LaunchBoulder", 1s)
{
	Requires(shooter);
}

void LaunchBoulderCommand::Initialize()
{
	shooter->setIndexerSpeed(1);
}

void LaunchBoulderCommand::End()
{
	shooter->setIndexerSpeed(0);
	shooter->stopShooter();

	shooter->ballReleased();
}




