#include "AssumeStartingConfigCommand.h"

#include "../../Config.h"

AssumeStartingConfigCommand::AssumeStartingConfigCommand(bool forward)
	: InstantCommand("AssumeStartingConfig"),
	m_facingForward(forward)
{
	Requires(drivetrain);
	Requires(shooter);
}

void AssumeStartingConfigCommand::Initialize()
{
	if (m_facingForward)
	{
		drivetrain->resetGyro();
	}
	else
	{
		drivetrain->setGyroAngle(180);
	}

	if (shooter->atTopLimit())
	{
		shooter->setEncoderPosition(Config::Shooter::maxHeight);
	}
}
