#ifndef OI_H
#define OI_H

#include "Joystick.h"
#include "Robotmap.h"

class OI {
public:
	OI();
	~OI();
	Joystick* getController();

protected:
	Joystick* controller;
};

#endif
