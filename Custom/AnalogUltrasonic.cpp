#include "AnalogUltrasonic.h"

#include "../Robotmap.h"

AnalogUltrasonic::AnalogUltrasonic(UINT8 moduleNumber, UINT32 channel) :
	AnalogChannel(moduleNumber, channel)
{

}
	
AnalogUltrasonic::AnalogUltrasonic(UINT32 channel) :
	AnalogChannel(channel)
{

}

float AnalogUltrasonic::getDistance()
{
	return GetVoltage()/.009765;
}