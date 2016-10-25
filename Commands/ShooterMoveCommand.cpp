#include "ShooterMoveCommand.h"

ShooterMoveCommand::ShooterMoveCommand(int speed)
	: DefaultCommand("Move Shooter"), m_speed(speed)
{
	Requires(shooter);
}

void ShooterMoveCommand::Initialize()
{
	if (m_speed != 0)
	{
		shooter->pivot(m_speed);
	}
	else
	{
		shooter->holdAt(shooter->getHeight());
	}
}

bool ShooterMoveCommand::IsFinished()
{
	if (m_speed > 0 && shooter->atTopLimit())
	{
		return true;
	}

	return m_speed < 0 && shooter->atBottomLimit();
}

void ShooterMoveCommand::End()
{
	shooter->pivot(0);
	//shooter->holdAt(shooter->getHeight());
}
