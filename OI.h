#pragma once

#include <vector>

#include "Controller/LogicalAxes.h"

class ControllerAxis;
class Button;
class JoystickButton;
class GenericController;

class OI {
public:
	OI();
	~OI();

	float getAxisValue(const int axis);

protected:
	GenericController* controllers[5]; // arbitrary choice of 4 controllers max
	std::vector<Button*> buttons;
	ControllerAxis* axes[logicalAxes::NumOfAxes];
};
