#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

protected:
	Joystick controller;

public:
	OI();

	float GetControllerAxis(int);
};

#endif
