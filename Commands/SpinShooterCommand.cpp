#include "SpinShooterCommand.h"

#include "../Config.h"

SpinShooterCommand::SpinShooterCommand(double speed) :
	DefaultCommand("SpinShooter"),
	m_speed(speed)
{
	Requires(shooter);
}

void SpinShooterCommand::Initialize()
{
	shooter->setShooterSpeed(m_speed);
}

bool SpinShooterCommand::IsFinished()
{
    return shooter->readyToFire();
}
