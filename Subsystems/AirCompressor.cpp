#include "AirCompressor.h"
#include "../Robotmap.h"
#include "../Commands/StartCompressorCommand.h"

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
