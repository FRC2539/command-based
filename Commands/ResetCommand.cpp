#include "ResetCommand.h"

ResetCommand::ResetCommand() {
	Requires(drivetrain);
	Requires(pickup);
	Requires(shooter);
}

void ResetCommand::Initialize() {
	drivetrain->directDrive(0, 0);
	pickup->pickup(0);
	shooter->reset();
}

void ResetCommand::Execute() {
}

bool ResetCommand::IsFinished() {
	return true;
}

void ResetCommand::End() {
}

void ResetCommand::Interrupted() {
}


