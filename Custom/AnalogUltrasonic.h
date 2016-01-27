#pragma once

#include <AnalogInput.h>

class AnalogUltrasonic: public AnalogInput {

public:
	AnalogUltrasonic(uint32_t channel);

	virtual ~AnalogUltrasonic();

	float getDistance();

};
