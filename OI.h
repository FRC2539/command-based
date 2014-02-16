#ifndef OI_H
#define OI_H

#include <unordered_map>

class ControllerButton;
class JoystickButton;
class GenericController;

class OI {
public:
	OI();
	~OI();

	GenericController* getController(int port=1);
	
	float getAxis(int port, std::string axis);
	bool getButton(int port, std::string button);
	
	ControllerButton* getControllerButton(std::string button);
	ControllerButton* getControllerButton(int port, std::string button);

protected:
	std::unordered_map<int, GenericController*> controllers;
	JoystickButton* preciseMovementButton;
	JoystickButton* fireButton;
	JoystickButton* openButton;
	JoystickButton* closeButton;
	JoystickButton* drawBackButton;
    JoystickButton* resetButton;
};

#endif
