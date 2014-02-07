#include "OpenCommand.h"
#include "../Robotmap.h"

OpenCommand::OpenCommand() {
	Requires(pickup);
}

void OpenCommand::Initialize() {
}

void OpenCommand::Execute() {
	pickup->open();
}

bool OpenCommand::IsFinished() {
	return false;
}

void OpenCommand::End() {
}

void OpenCommand::Interrupted() {
}
