#ifndef ANALOG_ULTRASONIC_H
#define ANALOG_ULTRASONIC_H

#include <AnalogChannel.h>

class AnalogUltrasonic: public AnalogChannel {

public:

	AnalogUltrasonic(uint8_t moduleNumber, uint32_t channel);
	AnalogUltrasonic(uint32_t channel);

	virtual ~AnalogUltrasonic();

	float getDistance();

};

#endif
