#include "AutomaticPickupCommand.h"

AutomaticPickupCommand::AutomaticPickupCommand() {
	Requires(pickup);
}

void AutomaticPickupCommand::Initialize() {
	pickup->pickup(1);
	SetTimeout(0.5);
}

void AutomaticPickupCommand::Execute() {
	//drivetrain->move(.7, 0);
}

bool AutomaticPickupCommand::IsFinished() {
	return IsTimedOut();
}

void AutomaticPickupCommand::End() {
	//drivetrain->move(0, 0);
	pickup->pickup(0);
}

void AutomaticPickupCommand::Interrupted() {
}
