#pragma once

#include <Commands/CommandGroup.h>

class DriveDistanceCommandGroup: public CommandGroup {
public:
	// distance should be in inches
	explicit DriveDistanceCommandGroup(float distance);

	std::vector<float> handoffPositions;
	std::vector<float> finalPositions;
};
