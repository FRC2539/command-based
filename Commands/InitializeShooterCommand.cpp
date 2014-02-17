#include "InitializeShooterCommand.h"

InitializeShooterCommand::InitializeShooterCommand() {
	Requires(shooter);
}

void InitializeShooterCommand::Initialize() {
	shooter->holdLauncher();
	SetTimeout(0.1);
}

void InitializeShooterCommand::Execute() {
}

bool InitializeShooterCommand::IsFinished() {
	return IsTimedOut();
}

void InitializeShooterCommand::End() {
	shooter->off();
}

void InitializeShooterCommand::Interrupted() {
}


