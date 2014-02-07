#include "AirCompressor.h"
#include "../Robotmap.h"

AirCompressor::AirCompressor() :
	Subsystem("AirCompressor")
	{
	compressor = new Compressor(PRESSURE_SWITCH_PORT, COMPRESSOR_PORT);
}

AirCompressor::~AirCompressor() {
	delete compressor;
}

void AirCompressor::start(){
	compressor->Start();
}
