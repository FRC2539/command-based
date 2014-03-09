#include "InstantCommand.h"

InstantCommand::InstantCommand(const char* name) : DefaultCommand(name) {}
InstantCommand::InstantCommand() : DefaultCommand() {}

bool InstantCommand::IsFinished() {
	return true;
}
