#include "StartCompressorCommand.h"

StartCompressorCommand::StartCompressorCommand()
	: DefaultCommand("StartCompressor")
{
	Requires(aircompressor);
}

void StartCompressorCommand::Initialize()
{
	aircompressor->start();
}
