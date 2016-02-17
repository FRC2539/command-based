#pragma once

#include "Types/ConditionalCommand.h"

class AutoDefenseTraverseZero : public ConditionalCommand {

public:
	AutoDefenseTraverseZero();

protected:
	bool shouldRun() override;
};
