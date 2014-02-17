#include "RunBackCommand.h"

RunBackCommand::RunBackCommand() {
	Requires(shooter);
}

void RunBackCommand::Initialize() {
	shooter->runBack();
}

void RunBackCommand::Execute() {
}

bool RunBackCommand::IsFinished() {
	return true;
}

void RunBackCommand::End() {
}

void RunBackCommand::Interrupted() {
}


