#include "FireCommand.h"

FireCommand::FireCommand() {
	Requires(shooter);
}

void FireCommand::Initialize() {
	shooter->releaseLauncher();
}

void FireCommand::Execute() {
}

bool FireCommand::IsFinished() {
	return true;
}

void FireCommand::End() {
}

void FireCommand::Interrupted() {
}
