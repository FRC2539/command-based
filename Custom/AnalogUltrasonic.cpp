#include "AnalogUltrasonic.h"

AnalogUltrasonic::AnalogUltrasonic(UINT8 moduleNumber, UINT32 channel) :
	AnalogChannel(moduleNumber, channel)
{

}
	
AnalogUltrasonic::AnalogUltrasonic(UINT32 channel) :
	AnalogChannel(channel)
{

}

AnalogUltrasonic::~AnalogUltrasonic()
{

}

float AnalogUltrasonic::getDistance()
{
	return GetVoltage()/.009765;
}