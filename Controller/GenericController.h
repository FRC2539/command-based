#ifndef GENERIC_CONTROLLER_H
#define GENERIC_CONTROLLER_H

#include "Joystick.h"
#include <unordered_set>
#include <unordered_map>

class GenericController : public Joystick {

	friend class ControllerAxis;
	friend class ControllerButton;

public:
	
	explicit GenericController(UINT32 port);
	GenericController(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

	virtual float GetX();
	virtual float GetY();
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	float GetAxis(UINT32 axis);
	virtual float GetAxis(const char* axis);
	virtual float GetButton(const char* button);

protected:
	virtual bool isInverted(UINT32 axis);
	std::unordered_map<const char*, int> axes;
	std::unordered_map<const char*, int> buttons;
	std::unordered_set<int> invertedAxes;
};

#endif
