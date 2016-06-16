#pragma once

#include "Commands/CommandGroup.h"

class LowBarCommandGroup: public CommandGroup {
public:
	LowBarCommandGroup();
	std::vector<float> positions;
};
