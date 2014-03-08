#include "RunBackCommand.h"

RunBackCommand::RunBackCommand() {
	Requires(shooter);
}

void RunBackCommand::Initialize() {
	shooter->runBack();
	SetTimeout(.55);
}

void RunBackCommand::Execute() {
}

bool RunBackCommand::IsFinished() {
	return IsTimedOut();
}

void RunBackCommand::End() {
	shooter->reset();
}

void RunBackCommand::Interrupted() {
	End();
}


