#include "StartCompressorCommand.h"

StartCompressorCommand::StartCompressorCommand()
	: InstantCommand("StartCompressor")
{
	Requires(aircompressor);
}

void StartCompressorCommand::Initialize()
{
	aircompressor->start();
}
