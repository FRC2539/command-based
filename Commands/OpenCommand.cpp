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
	return true;
}

void OpenCommand::End() {
}

void OpenCommand::Interrupted() {
}
