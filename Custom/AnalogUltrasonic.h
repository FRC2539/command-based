#ifndef ANALOG_ULTRASONIC_H
#define ANALOG_ULTRASONIC_H

#include <AnalogInput.h>

class AnalogUltrasonic: public AnalogInput {

public:
	AnalogUltrasonic(uint32_t channel);

	virtual ~AnalogUltrasonic();

	float getDistance();

};

#endif
