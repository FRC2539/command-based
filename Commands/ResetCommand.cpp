#include "ResetCommand.h"

ResetCommand::ResetCommand() {
	Requires(drivetrain);
	Requires(pickup);
	Requires(shooter);
}

void ResetCommand::Initialize() {
	drivetrain->move(0, 0);
	pickup->pickup(0);
	shooter->reset();

	SetTimeout(0.2);
}

void ResetCommand::Execute() {
}

bool ResetCommand::IsFinished() {
	return IsTimedOut();
}

void ResetCommand::End() {
	shooter->off();
}

void ResetCommand::Interrupted() {
}


