#include "AirCompressor.h"

#include <Compressor.h>
#include "../Commands/StartCompressorCommand.h"

AirCompressor::AirCompressor() : Subsystem("AirCompressor")
{
	compressor = new Compressor();

	DEBUG_SENSOR(compressor);
}

AirCompressor::~AirCompressor()
{
	delete compressor;
}

void AirCompressor::InitDefaultCommand()
{
	SetDefaultCommand(new StartCompressorCommand());
}

void AirCompressor::start()
{
	compressor->Start();
}
