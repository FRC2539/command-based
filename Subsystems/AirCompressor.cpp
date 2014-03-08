#include "AirCompressor.h"

#include "Compressor.h"

#include "../Commands/StartCompressorCommand.h"

#include "../RobotMap.h"

AirCompressor::AirCompressor() :
	Subsystem("AirCompressor")
{
	compressor = new Compressor(PRESSURE_SWITCH_PORT, COMPRESSOR_PORT);
}

AirCompressor::~AirCompressor() {
	delete compressor;
}

void AirCompressor::InitDefaultCommand() {
	SetDefaultCommand(new StartCompressorCommand());
}

void AirCompressor::start(){
	compressor->Start();
}
