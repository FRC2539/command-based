#include "AnalogUltrasonic.h"

AnalogUltrasonic::AnalogUltrasonic(uint32_t channel) :
	AnalogInput(channel) {}

AnalogUltrasonic::~AnalogUltrasonic() {}

float AnalogUltrasonic::getDistance()
{
	return GetVoltage()/.009765;
}
