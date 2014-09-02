#ifndef CONTROLLER_AXIS_H
#define CONTROLLER_AXIS_H

class GenericController;
#include <string>

class ControllerAxis
{
public:
	ControllerAxis(GenericController* control, std::string axis);
	virtual ~ControllerAxis();
	
	virtual void setModifier(float mod);

	virtual float getValue();

protected:
	GenericController* controller;
	UINT32 axisNumber;
	float modifier;
};

#endif