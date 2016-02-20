#include "LowGoalCommand.h"

#include "LowGoalCommandGroup.h"

LowGoalCommand::LowGoalCommand() : ConditionalCommand("LowGoal")
{
	m_command = new LowGoalCommandGroup();
}

bool LowGoalCommand::shouldRun()
{
	return shooter->hasBall();
}
