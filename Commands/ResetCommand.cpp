#include "ResetCommand.h"

ResetCommand::ResetCommand() {
	std::cout << "ResetCommand Requires(drivetrain)\n";
	Requires(drivetrain);
	std::cout << "ResetCommand Requires(pickup)\n";
	Requires(pickup);
	std::cout << "ResetCommand Requires(shooter)\n";
	Requires(shooter);
}

void ResetCommand::Initialize() {
	drivetrain->move(0, 0);
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


