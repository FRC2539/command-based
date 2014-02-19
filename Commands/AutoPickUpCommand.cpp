#include "AutoPickUpCommand.h"

AutoPickUpCommand::AutoPickUpCommand(float direction, float seconds) {
	Requires(pickup);
	m_direction = direction;
	m_seconds = seconds;
}

void AutoPickUpCommand::Initialize() {
	pickup->pickup(m_direction);
	SetTimeout(m_seconds);
}

void AutoPickUpCommand::Execute() {
}

bool AutoPickUpCommand::IsFinished() {
	return IsTimedOut();
}

void AutoPickUpCommand::End() {
	pickup->pickup(0);
}

void AutoPickUpCommand::Interrupted() {
}
