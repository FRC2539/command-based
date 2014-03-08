#include "DrawBackCommand.h"

DrawBackCommand::DrawBackCommand() {
	Requires(shooter);
}

void DrawBackCommand::Initialize() {
	shooter->retractLauncher();
	SetTimeout(2.5);
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

