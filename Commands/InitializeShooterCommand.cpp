#include "InitializeShooterCommand.h"

InitializeShooterCommand::InitializeShooterCommand() {
	Requires(shooter);
}

void InitializeShooterCommand::Initialize() {
	shooter->reset();
	SetTimeout(0.2);
}

void InitializeShooterCommand::Execute() {
}

bool InitializeShooterCommand::IsFinished() {
	return IsTimedOut();
}

void InitializeShooterCommand::End() {
	shooter->reset();
}

void InitializeShooterCommand::Interrupted() {
}


