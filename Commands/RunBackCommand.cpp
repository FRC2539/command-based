#include "RunBackCommand.h"

RunBackCommand::RunBackCommand() : TimedCommand("RunBack", .55)
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


