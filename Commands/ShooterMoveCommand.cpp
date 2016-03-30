#include "ShooterMoveCommand.h"

#include "../Config.h"

ShooterMoveCommand::ShooterMoveCommand(Shooter::Direction direction)
	: DefaultCommand("Shooter"), m_direction(direction)
{
	Requires(shooter);
}

void ShooterMoveCommand::Initialize()
{
	shooter->move(m_direction);
}

bool ShooterMoveCommand::IsFinished()
{
	if (m_direction == Shooter::UP && shooter->atTopLimit())
	{
		shooter->setEncoderPosition(Config::Shooter::maxHeight);

		return true;
	}
	if (m_direction == Shooter::DOWN && shooter->atBottomLimit())
	{
		shooter->setEncoderPosition(Config::Shooter::minHeight);

		return true;
	}

	return false;
}

void ShooterMoveCommand::End()
{
	shooter->holdAt(shooter->getHeight());
	shooter->storeEncoderPosition();
}