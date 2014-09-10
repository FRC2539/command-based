#ifndef CONTROLLER_AXIS_H
#define CONTROLLER_AXIS_H

class GenericController;

class ControllerAxis
{
public:
	ControllerAxis(GenericController* control, const char* axisName);
	virtual ~ControllerAxis();
	
	virtual void setModifier(float mod);
	virtual void invertAxis();
	virtual void makeThrottle();

	virtual float getValue();

protected:
	GenericController* controller;
	const char* axis;
	float modifier;
	bool throttle;
};

#endif