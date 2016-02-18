#pragma once

#include "Types/DefaultCommand.h"

class MotorTestCommand : public DefaultCommand {

public:
	explicit MotorTestCommand(float speed);
	void Initialize() override;
	void End() override;

protected:
	float m_speed;
};
