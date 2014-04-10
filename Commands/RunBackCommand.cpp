#include "RunBackCommand.h"

RunBackCommand::RunBackCommand() : TimedCommand("RunBack", 1.75)
{
	Requires(shooter);
}

void RunBackCommand::Initialize()
{
	shooter->runBack();
}

void RunBackCommand::End() {
	shooter->reset();
}


