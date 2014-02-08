#ifndef OI_H
#define OI_H

#include "Controller/GenericController.h"
#include "Robotmap.h"

class JoystickButton;

class OI {
public:
	OI();
	~OI();
	GenericController* getController();

protected:
	GenericController* controller;
	JoystickButton* preciseMovementButton;
	JoystickButton* fireButton;
	JoystickButton* openButton;
	JoystickButton* closeButton;
	JoystickButton* drawBackButton;
	
};

#endif
