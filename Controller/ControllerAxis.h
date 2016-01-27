#pragma once

class GenericController;
#include <cstdint>

class ControllerAxis
{
public:
	ControllerAxis(GenericController* control, uint32_t axisEnum);
	virtual ~ControllerAxis();
	
	virtual void setModifier(float mod);
	virtual void invertAxis();
	virtual void makeThrottle();

	virtual float getValue();

protected:
	GenericController* controller;
	uint32_t axis;
	float modifier;
	bool throttle;
};
