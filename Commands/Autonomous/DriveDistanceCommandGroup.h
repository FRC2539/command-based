#pragma once

#include <Commands/CommandGroup.h>

class DriveDistanceCommandGroup: public CommandGroup {
public:
	// distance should be in inches
	explicit DriveDistanceCommandGroup(float distance);

	std::vector<double> handoffPositions;
	std::vector<double> finalPositions;
};
