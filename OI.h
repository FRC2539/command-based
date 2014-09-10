#ifndef OI_H
#define OI_H

#include <unordered_map>
#include <vector>

class ControllerAxis;
class ControllerButton;
class JoystickButton;
class GenericController;

class OI {
public:
	OI();
	~OI();

	float getAxisValue(const char* axisName);

protected:
	std::unordered_map<int, GenericController*> controllers;
	std::vector<ControllerButton*> buttons;
	std::unordered_map<const char*, ControllerAxis*> axes;
};

#endif
