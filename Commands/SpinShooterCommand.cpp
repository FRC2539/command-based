#include "SpinShooterCommand.h"

#include "../Config.h"

SpinShooterCommand::SpinShooterCommand() :
	DefaultCommand("SpinShooter")
{
	Requires(shooter);
}

void SpinShooterCommand::Initialize()
{
	shooter->setShooterSpeed(Config::Shooter::firingSpeed);
}

bool SpinShooterCommand::IsFinished()
{
    return shooter->readyToFire();
}
