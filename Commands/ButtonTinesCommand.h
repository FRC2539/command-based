#ifndef BUTTON_TINES_COMMAND_H
#define BUTTON_TINES_COMMAND_H

#include "Types/DefaultCommand.h"

class ButtonTinesCommand : public DefaultCommand {

public:
	ButtonTinesCommand(float speed);
	void Initialize();
	void IsFinished();
	void End();

protected:
	float m_speed;
};

#endif
