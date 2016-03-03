#pragma once

#include "../Types/InstantCommand.h"

class AssumeStartingConfigCommand : public InstantCommand {

public:
	AssumeStartingConfigCommand();
	void Initialize() override;
};
