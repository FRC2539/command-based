#include "PickupCommand.h"

#include "PickupCommandGroup.h"

PickupCommand::PickupCommand() : ConditionalCommand("Pickup")
{
	m_command = new PickupCommandGroup();
}

bool PickupCommand::shouldRun()
{
	//return !shooter->hasBall();
	return true;
}
