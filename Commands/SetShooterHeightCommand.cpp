#include "SetShooterHeightCommand.h"

SetShooterHeightCommand::SetShooterHeightCommand(int height) :
	InstantCommand("SetShooterHeight"),
	m_height(height) {}

void SetShooterHeightCommand::Initialize()
{
	shooter->pivotToHeight(m_height);
}

