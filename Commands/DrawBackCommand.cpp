#include "DrawBackCommand.h"
#include "../Robotmap.h"

DrawBackCommand::DrawBackCommand() {

	Requires(shooter);
}

void DrawBackCommand::Initialize() {

}

void DrawBackCommand::Execute()
{
	shooter->retractLauncher();
}

bool DrawBackCommand::IsFinished() {
	return true;
}

void DrawBackCommand::End() {
	shooter->off();
}

void DrawBackCommand::Interrupted() {
}

