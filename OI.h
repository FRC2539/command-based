#ifndef OI_H
#define OI_H

#include <string>
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

	std::vector<float> getAxes(std::string system);

protected:
	std::unordered_map<int, GenericController*> controllers;
	std::vector<ControllerButton*> buttons;
	std::unordered_map<std::string, std::vector<ControllerAxis*>> axes;
};

#endif
