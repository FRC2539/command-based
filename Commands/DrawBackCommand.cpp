#include "DrawBackCommand.h"

DrawBackCommand::DrawBackCommand() {
	std::cout << "DrawBackCommand Requires(shooter)\n";
	Requires(shooter);
}

void DrawBackCommand::Initialize() {
	shooter->retractLauncher();
	SetTimeout(5);
}

void DrawBackCommand::Execute() {
}

bool DrawBackCommand::IsFinished() {

	return IsTimedOut() || shooter->down();
}

void DrawBackCommand::End() {
	shooter->reset();
}

void DrawBackCommand::Interrupted() {
	End();
}

