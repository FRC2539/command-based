#include "RunBackCommand.h"

RunBackCommand::RunBackCommand() {
	Requires(shooter);
}

void RunBackCommand::Initialize() {
	shooter->runBack();
	SetTimeout(1);
}

void RunBackCommand::Execute() {
}

bool RunBackCommand::IsFinished() {
	return IsTimedOut();
}

void RunBackCommand::End() {
	shooter->holdLauncher();
}

void RunBackCommand::Interrupted() {
}

