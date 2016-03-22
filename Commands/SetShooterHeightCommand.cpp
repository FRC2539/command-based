#include "SetShooterHeightCommand.h"

SetShooterHeightCommand::SetShooterHeightCommand(int height) :
	DefaultCommand("SetShooterHeight"),
	m_height(height)
{
	Requires(shooter);
}

void SetShooterHeightCommand::Initialize()
{
	shooter->pivotToHeight(m_height);
}

bool SetShooterHeightCommand::IsFinished()
{
	return std::abs(shooter->getHeight() - m_height) < 10;
}

void SetShooterHeightCommand::End()
{
	shooter->storeEncoderPosition();
}

