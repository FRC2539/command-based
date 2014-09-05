#ifndef CONTROLLER_AXIS_H
#define CONTROLLER_AXIS_H

class GenericController;
#include <string>

class ControllerAxis
{
public:
	ControllerAxis(GenericController* control, std::string axisName);
	virtual ~ControllerAxis();
	
	virtual void setModifier(float mod);
	virtual void makeThrottle();

	virtual float getValue();

protected:
	GenericController* controller;
	std::string axis;
	float modifier;
	bool throttle;
};

#endif