#pragma once

#include "Types/ConditionalCommand.h"

class AutoDefenseTraverse180 : public ConditionalCommand {

public:
	AutoDefenseTraverse180();

protected:
	bool shouldRun() override;
};
