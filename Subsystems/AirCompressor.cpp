#include "AirCompressor.h"

#include "Compressor.h"

#include "../Commands/StartCompressorCommand.h"

#include "../RobotMap.h"

#ifndef COMPRESSOR_PORT
#define COMPRESSOR_PORT 0
#endif
#ifndef PRESSURE_SWITCH_PORT
#define PRESSURE_SWITCH_PORT 0
#endif

AirCompressor::AirCompressor() : Subsystem("AirCompressor")
{
	compressor = new Compressor(PRESSURE_SWITCH_PORT, COMPRESSOR_PORT);
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
