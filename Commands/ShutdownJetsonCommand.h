#pragma once

#include "Types/InstantCommand.h"

class ShutdownJetsonCommand : public InstantCommand {

public:
	ShutdownJetsonCommand();
	void Initialize() override;
};
