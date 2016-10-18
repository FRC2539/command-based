#pragma once

#include "Types/DefaultCommand.h"

class StallMotorCommand : public DefaultCommand {

public:
	StallMotorCommand();

	void Initialize() override;
};
