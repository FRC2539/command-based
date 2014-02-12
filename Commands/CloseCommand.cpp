#include "CloseCommand.h"

CloseCommand::CloseCommand() {
	Requires(pickup);
}

void CloseCommand::Initialize() {
	pickup->close();
}

void CloseCommand::Execute() {
}

bool CloseCommand::IsFinished() {
	return true;
}

void CloseCommand::End() {
}

void CloseCommand::Interrupted() {
}
