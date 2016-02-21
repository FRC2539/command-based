#pragma once

#include "Types/TimedCommand.h"

class LaunchBoulderCommand : public TimedCommand {

public:
	explicit LaunchBoulderCommand();
	void Initialize() override;
	void End() override;
};
