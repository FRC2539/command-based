#pragma once

#include "Types/DefaultCommand.h"

class CollectBoulderCommand : public DefaultCommand {

public:
	explicit CollectBoulderCommand();
	void Initialize() override;
	bool IsFinished() override;
	void End() override;
};
