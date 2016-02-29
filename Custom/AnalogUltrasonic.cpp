#include "AnalogUltrasonic.h"

AnalogUltrasonic::AnalogUltrasonic(uint32_t channel) :
	AnalogInput(channel) {}

float AnalogUltrasonic::getDistance()
{
	return GetVoltage()/.009765;
}
