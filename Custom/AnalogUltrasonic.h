#ifndef ANALOG_ULTRASONIC_H
#define ANALOG_ULTRASONIC_H

#include <AnalogChannel.h>

class AnalogUltrasonic: public AnalogChannel {

public:

	AnalogUltrasonic(UINT8 moduleNumber, UINT32 channel);
	AnalogUltrasonic(UINT32 channel);

	virtual ~AnalogUltrasonic();

	float getDistance();

};

#endif
