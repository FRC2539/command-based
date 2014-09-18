#include "AnalogUltrasonic.h"

AnalogUltrasonic::AnalogUltrasonic(UINT8 moduleNumber, uint32_t channel) :
	AnalogChannel(moduleNumber, channel) {}
	
AnalogUltrasonic::AnalogUltrasonic(uint32_t channel) :
	AnalogChannel(channel) {}

AnalogUltrasonic::~AnalogUltrasonic() {}

float AnalogUltrasonic::getDistance()
{
	return GetVoltage()/.009765;
}
