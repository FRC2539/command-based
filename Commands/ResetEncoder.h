#pragma once

#include "Types/InstantCommand.h"

class ResetEncoder : public InstantCommand {

public:
	ResetEncoder();
	void Initialize() override;
};
