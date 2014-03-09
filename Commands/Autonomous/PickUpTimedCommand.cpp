#include "PickUpTimedCommand.h"

PickUpTimedCommand::PickUpTimedCommand(float direction, double seconds)
	: TimedCommand("PickUpTimed", seconds)
{
	Requires(pickup);
	m_direction = direction;
}

void PickUpTimedCommand::Initialize()
{
	pickup->pickup(m_direction);
}

void PickUpTimedCommand::End()
{
	pickup->pickup(0);
}
