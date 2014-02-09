#include "DrawBackCommand.h"
#include "../Robotmap.h"

DrawBackCommand::DrawBackCommand() {
	Requires(shooter);
}

void DrawBackCommand::Initialize() {
	shooter->retractLauncher();
}

void DrawBackCommand::Execute()
{
}

bool DrawBackCommand::IsFinished() {
	return false;
}

void DrawBackCommand::End() {
	shooter->off();
}

void DrawBackCommand::Interrupted() {
}

