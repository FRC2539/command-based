#include "AirCompressor.h"
#include "../Robotmap.h"

AirCompressor::AirCompressor() :
	Subsystem("AirCompressor")
	{
	compressor = new Compressor(PRESSURE_SWITCH_PORT, COMPRESSOR_PORT);
	compressor->Start();
}

AirCompressor::~AirCompressor() {
	delete compressor;
}
