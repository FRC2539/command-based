#include "DrawBackCommand.h"
#include "../Robotmap.h"

DrawBackCommand::DrawBackCommand() {
	Requires(shooter);
}

void DrawBackCommand::Initialize() {
	controller = oi->getController();
}

void DrawBackCommand::Execute()
{
	if (controller->GetButton(DRAWBACK_BUTTON))
	{
		shooter->retractLauncher();
	}
	else
	{
		shooter->off();
	}
}

bool DrawBackCommand::IsFinished() {
	return false;
}

void DrawBackCommand::End() {
}

void DrawBackCommand::Interrupted() {
}

