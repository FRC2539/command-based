#pragma once

#include "Types/DefaultCommand.h"

class ShooterMoveCommand : public DefaultCommand {

public:
	ShooterMoveCommand(int speed);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	int m_speed;
};
