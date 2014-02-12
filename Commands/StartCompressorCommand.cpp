#include "StartCompressorCommand.h"

StartCompressorCommand::StartCompressorCommand() {
	Requires(aircompressor);
}

void StartCompressorCommand::Initialize() {
	aircompressor->start();
}

void StartCompressorCommand::Execute() {
}

bool StartCompressorCommand::IsFinished() {
	return true;
}

void StartCompressorCommand::End() {
}

void StartCompressorCommand::Interrupted() {
}


