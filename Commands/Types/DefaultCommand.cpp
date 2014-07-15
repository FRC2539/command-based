#include "DefaultCommand.h"

DefaultCommand::DefaultCommand(const char* name, double timeout)
	: CommandBase(name, timeout) {}
DefaultCommand::DefaultCommand(const char* name) : CommandBase(name) {}
DefaultCommand::DefaultCommand(double timeout) : CommandBase(timeout) {}
DefaultCommand::DefaultCommand() : CommandBase() {}

void DefaultCommand::Initialize() {}

void DefaultCommand::Execute() {}

bool DefaultCommand::IsFinished() {
	return false;
}

void DefaultCommand::End() {}

void DefaultCommand::Interrupted() {
	End();
}
