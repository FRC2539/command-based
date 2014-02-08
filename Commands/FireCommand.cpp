#include "FireCommand.h"
#include "../Robotmap.h"

FireCommand::FireCommand() {
	Requires(shooter);
}

void FireCommand::Initialize() {
}

void FireCommand::Execute() {
	shooter->releaseLauncher();
}

bool FireCommand::IsFinished() {
	return true;
}

void FireCommand::End() {
}

void FireCommand::Interrupted() {
}


