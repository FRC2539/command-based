#include "PickUpCommand.h"

PickUpCommand::PickUpCommand(float direction) : DefaultCommand("PickUp")
{
	Requires(pickup);

	m_direction = direction;
}

void PickUpCommand::Initialize()
{
	pickup->pickup(m_direction);
}

void PickUpCommand::End()
{
	pickup->pickup(0);
}
