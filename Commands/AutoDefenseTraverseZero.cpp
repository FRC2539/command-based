#include "AutoDefenseTraverseZero.h"
#include "AlignmentTurnCommand.h"

AutoDefenseTraverseZero::AutoDefenseTraverseZero() : ConditionalCommand("AutoDefenseTraverseZero") {
	m_command = new AlignmentTurnCommand(0);
}

bool AutoDefenseTraverseZero::shouldRun()
{
	double angle = drivetrain->getAngle();
	return angle < 90 || angle >= 270;
}

