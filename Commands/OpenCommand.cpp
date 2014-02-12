#include "OpenCommand.h"

OpenCommand::OpenCommand() {
	Requires(pickup);
}

void OpenCommand::Initialize() {
	pickup->open();
}

void OpenCommand::Execute() {
}

bool OpenCommand::IsFinished() {
	return true;
}

void OpenCommand::End() {
}

void OpenCommand::Interrupted() {
}
