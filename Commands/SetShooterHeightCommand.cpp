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
		m_direction = Shooter::DOWN;
	}
	else
	{
		m_direction = Shooter::UP;
	}
	shooter->move(m_direction);
}

bool SetShooterHeightCommand::IsFinished()
{
	if (m_direction == Shooter::UP && shooter->atTopLimit())
	{
		m_height = Config::Shooter::maxHeight;
		shooter->setEncoderPosition(m_height);

		return true;
	}
	if (m_direction == Shooter::DOWN && shooter->atBottomLimit())
	{
		m_height = Config::Shooter::minHeight;
		shooter->setEncoderPosition(m_height);

		return true;
	}

	return std::abs(shooter->getHeight() - m_height) < 30;
}

void SetShooterHeightCommand::End()
{
	shooter->holdAt(m_height);
	shooter->storeEncoderPosition();
}

