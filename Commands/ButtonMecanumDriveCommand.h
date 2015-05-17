#ifndef BUTTON_MECANUM_DRIVE_COMMAND_H
#define BUTTON_MECANUM_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class ButtonMecanumDriveCommand : public DefaultCommand {

public:
	ButtonMecanumDriveCommand(float x, float y, float rotate=0);
	void Initialize();
	void End();

protected:
	float m_x;
	float m_y;
	float m_rotate;
};

#endif
