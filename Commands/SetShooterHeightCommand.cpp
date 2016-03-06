#include "SetShooterHeightCommand.h"

SetShooterHeightCommand::SetShooterHeightCommand(int i) :
	DefaultCommand("SetShooterHeight"),
	m_height(i)
{
	Requires(shooter);
}

void SetShooterHeightCommand::Initialize()
{
	if (m_height == 1)
	{
		shooter->pivotToHeight(-.5);
	}
	else if (m_height != 1)
	{
		shooter->pivotToHeight(.5);
	}
}