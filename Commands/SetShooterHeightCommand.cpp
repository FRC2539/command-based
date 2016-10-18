#include "SetShooterHeightCommand.h"
#include "../Custom/Netconsole.h"

#include "../Config.h"

SetShooterHeightCommand::SetShooterHeightCommand(double height):
	DefaultCommand("SetShooterHeight"),
	m_height(height)
{
	Requires(shooter);
}

void SetShooterHeightCommand::Initialize()
{
	Netconsole::instant("iHeight: ", shooter->getHeight());
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
	shooter->pivot(m_speed);
	Netconsole::instant("difference: ", std::abs(shooter->getHeight() - m_height));
	return std::abs(shooter->getHeight() - m_height) < .05;
}

void SetShooterHeightCommand::End()
{
	Netconsole::instant("fHeight: ", shooter->getHeight());
	shooter->pivot(0);
	//shooter->holdAt(m_height);
}

