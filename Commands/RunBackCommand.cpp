#include "RunBackCommand.h"

RunBackCommand::RunBackCommand() {
	std::cout << "RunBackCommand Requires(shooter)\n";
	Requires(shooter);
}

void RunBackCommand::Initialize() {
	shooter->runBack();
	SetTimeout(1.5);
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


