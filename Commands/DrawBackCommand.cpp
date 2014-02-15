#include "DrawBackCommand.h"
#include "RunBackCommand.h"

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
	//shooter->holdLauncher();
	Command* command = new RunBackCommand();
	command->Start();
}

void DrawBackCommand::Interrupted() {
}

