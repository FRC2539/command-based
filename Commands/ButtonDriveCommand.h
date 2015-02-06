#ifndef BUTTON_DRIVE_COMMAND_H
#define BUTTON_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class ButtonDriveCommand : public DefaultCommand {

public:
	ButtonDriveCommand(float speed);
	void Initialize();
	void End();

protected:
	float m_speed;
};

#endif
