#include "DrawBackCommand.h"
#include <iostream>

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
	shooter->holdLauncher();
}

void DrawBackCommand::Interrupted() {
}

