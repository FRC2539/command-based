#include "SpinShooterCommand.h"

#include "../Config.h"

SpinShooterCommand::SpinShooterCommand() :
	DefaultCommand("SpinShooter")
{
	Requires(shooter);
}

void SpinShooterCommand::Initialize()
{
	shooter->setShooterSpeed(.3);
}

bool SpinShooterCommand::IsFinished()
{
    return shooter->readyToFire();
}
