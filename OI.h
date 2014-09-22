#ifndef OI_H
#define OI_H

#include <unordered_map>
#include <vector>

#include "Controller/LogicalAxes.h"

class ControllerAxis;
class ControllerButton;
class JoystickButton;
class GenericController;

class OI {
public:
	OI();
	~OI();

	float getAxisValue(const int axis);

protected:
	GenericController* controllers[5]; // arbitrary choice of 4 controllers max
	std::vector<ControllerButton*> buttons;
	ControllerAxis* axes[logicalAxes::NumOfAxes];
};

#endif
