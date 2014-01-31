#ifndef GENERIC_CONTROLLER_H
#define GENERIC_CONTROLLER_H

#include "Joystick.h"
#include <unordered_set>
#include <unordered_map>

class GenericController : public Joystick {

public:
	
    explicit GenericController(UINT32 port);
    GenericController(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

	virtual float GetX();
    virtual float GetY();
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	float GetAxis(UINT32 axis);
	virtual float GetAxis(std::string axis);
	virtual float GetButton(std::string button);

protected:
    virtual bool isInverted(UINT32 axis);
	std::unordered_map<std::string, int> axes;
	std::unordered_map<std::string, int> buttons;
	std::unordered_set<int> invertedAxes;
};

#endif
