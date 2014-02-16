#include "DrawBackCommand.h"

DrawBackCommand::DrawBackCommand() {
	Requires(shooter);
}

void DrawBackCommand::Initialize() {
	shooter->retractLauncher();
}

void DrawBackCommand::Execute() {
}

bool DrawBackCommand::IsFinished() {
	return shooter->down();
}

void DrawBackCommand::End() {
	shooter->runBack();
}

void DrawBackCommand::Interrupted() {
}

