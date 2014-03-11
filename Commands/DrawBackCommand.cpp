#include "DrawBackCommand.h"

DrawBackCommand::DrawBackCommand() : TimedCommand("DrawBack", 2.5)
{
	Requires(shooter);
}

void DrawBackCommand::Initialize()
{
	shooter->retractLauncher();
}

bool DrawBackCommand::IsFinished()
{
	return TimedCommand::IsFinished() || shooter->isDown();
}

void DrawBackCommand::End()
{
	shooter->reset();
}

