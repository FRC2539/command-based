#include "SetShooterHeightCommand.h"

#include "../Config.h"

SetShooterHeightCommand::SetShooterHeightCommand(int height) :
	DefaultCommand("SetShooterHeight"),
	m_height(height)
{
	Requires(shooter);
}

void SetShooterHeightCommand::Initialize()
{
	if (shooter->getHeight() > m_height)
	{
		m_speed = -Config::Shooter::pivotSpeed;
	}
	else
	{
		m_speed = Config::Shooter::pivotSpeed;
	}
	shooter->pivot(m_speed);
}

bool SetShooterHeightCommand::IsFinished()
{
	if (m_speed > 0 && shooter->atTopLimit())
	{
		m_height = Config::Shooter::maxHeight;

		return true;
	}
	if (m_speed < 0 && shooter->atBottomLimit())
	{
		m_height = Config::Shooter::minHeight;

		return true;
	}

	return std::abs(shooter->getHeight() - m_height) < 100;
}

void SetShooterHeightCommand::End()
{
	shooter->pivot(0);
	//shooter->holdAt(m_height);
}

