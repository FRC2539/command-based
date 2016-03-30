#pragma once

#include "Types/DefaultCommand.h"

class ShooterMoveCommand : public DefaultCommand {

public:
	ShooterMoveCommand(Shooter::Direction direction);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	Shooter::Direction m_direction;
};