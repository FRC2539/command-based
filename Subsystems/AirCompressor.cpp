#include "AirCompressor.h"
#include "../Robotmap.h"

AirCompressor::AirCompressor() :
	Subsystem("AirCompressor")
	{
	compressor = new Compressor(COMPRESSOR_MODULE, COMPRESSOR_PORT);
	compressor->Start();
}

AirCompressor::~AirCompressor() {
	delete compressor;
}
