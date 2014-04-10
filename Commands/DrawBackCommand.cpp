#include "DrawBackCommand.h"
#include <iostream>

DrawBackCommand::DrawBackCommand() : TimedCommand("DrawBack", 4)
{
	Requires(shooter);
}

void DrawBackCommand::Initialize()
{
	std::cout << "Initialize\n";
	shooter->retractLauncher();
}

bool DrawBackCommand::IsFinished()
{
	std::cout << "IsFinished\n";
	return TimedCommand::IsFinished() || shooter->isDown();
}

void DrawBackCommand::End()
{
	std::cout << "end\n";
	shooter->reset();
}

