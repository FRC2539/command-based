#include "AutoDefenseTraverse180.h"
#include "AlignmentTurnCommand.h"

AutoDefenseTraverse180::AutoDefenseTraverse180() : ConditionalCommand("AutoDefenseTraverse180") {
	m_command = new AlignmentTurnCommand(180);
}

bool AutoDefenseTraverse180::shouldRun()
{
	double angle = drivetrain->getAngle();
	return angle >= 90 && angle < 270;
}

