#ifndef BUTTON_DRIVE_COMMAND_H
#define BUTTON_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class ButtonDriveCommand : public DefaultCommand {

public:
	ButtonDriveCommand(float x, float y, float rotate=0);
	void Initialize();
	void End();

protected:
	float m_x;
	float m_y;
	float m_rotate;
};

#endif
