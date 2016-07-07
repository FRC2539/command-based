#pragma once

#include "../Types/InstantCommand.h"

class TurnAngleCommandGroup;

class CalculateAngleCommand : public InstantCommand {

public:
	explicit CalculateAngleCommand(float distance);
	void Initialize();

protected:
	float m_distance;
	float m_handoffDistance;
	TurnAngleCommandGroup* m_parent;
};
