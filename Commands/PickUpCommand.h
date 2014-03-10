#ifndef PICK_UP_COMMAND_H
#define PICK_UP_COMMAND_H

#include "Types/DefaultCommand.h"

class PickUpCommand : public DefaultCommand {

public:
	PickUpCommand(float direction);
	void Initialize();
	void End();

protected:
	float m_direction;
};

#endif
