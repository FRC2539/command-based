#include "DefaultCommand.h"

DefaultCommand::DefaultCommand(const char* name) : CommandBase(name) {}

DefaultCommand::DefaultCommand() : CommandBase() {}

void DefaultCommand::Initialize() {}

void DefaultCommand::Execute() {}

bool DefaultCommand::IsFinished()
{
	return false;
}

void DefaultCommand::End() {}

void DefaultCommand::Interrupted()
{
	End();
}
