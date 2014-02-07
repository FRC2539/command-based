#include "CloseCommand.h"
#include "../Robotmap.h"

CloseCommand::CloseCommand() {
	Requires(pickup);
}

void CloseCommand::Initialize() {
}

void CloseCommand::Execute() {
	pickup->close();
}

bool CloseCommand::IsFinished() {
	return false;
}

void CloseCommand::End() {
}

void CloseCommand::Interrupted() {
}
