#pragma once

#include "../Types/InstantCommand.h"

class DriveDistanceCommandGroup;

class CalculatePositionsCommand : public InstantCommand {

public:
	explicit CalculatePositionsCommand(float distance);
	void Initialize();

protected:
	float m_distance;
	float m_handoffDistance;
	DriveDistanceCommandGroup* m_parent;
};
