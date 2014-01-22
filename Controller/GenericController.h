#ifndef GENERIC_CONTROLLER_H
#define GENERIC_CONTROLLER_H

#include "Joystick.h"
#include <unordered_set>

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
	virtual float GetAxis(AxisType axis);
	virtual bool GetButton(int button);

protected:
    virtual bool isInverted(UINT32 axis);
	std::unordered_set<int> invertedAxes;
};

#endif
