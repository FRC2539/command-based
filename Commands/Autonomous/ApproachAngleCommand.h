#pragma once

#include "../Types/DefaultCommand.h"

class TurnAngleCommandGroup;

class ApproachAngleCommand : public DefaultCommand {

public:
	explicit ApproachAngleCommand(float distance);

	void Initialize() override;
	bool IsFinished() override;
	void End() override;

protected:
	TurnAngleCommandGroup* m_parent;
	int m_direction;
};
