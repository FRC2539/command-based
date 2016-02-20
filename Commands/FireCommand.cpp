#include "FireCommand.h"

#include "FireCommandGroup.h"

FireCommand::FireCommand() : ConditionalCommand("Fire")
{
	m_command = new FireCommandGroup();
}

bool FireCommand::shouldRun()
{
	if (shooter->hasBall() == false)
	{
		return false;
	}

	auto target = shooter->getTarget();
	return target.found;
}
