#include "AirCompressor.h"

#include "Compressor.h"

#include "../Commands/StartCompressorCommand.h"

#include "../RobotMap.h"

AirCompressor::AirCompressor() : Subsystem("AirCompressor")
{
	compressor = new Compressor(
		RobotMap::Pneumatics::pressureSwitchPort,
		RobotMap::Pneumatics::airCompressorPort
	);
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
