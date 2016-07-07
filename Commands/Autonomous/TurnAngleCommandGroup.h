#pragma once

#include <Commands/CommandGroup.h>

class TurnAngleCommandGroup: public CommandGroup {
public:
	// angle should be in degrees
	explicit TurnAngleCommandGroup(float angle);

	std::vector<float> handoffPositions;
	std::vector<float> finalPositions;
};
