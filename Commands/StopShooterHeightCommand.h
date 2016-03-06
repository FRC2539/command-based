#pragma once

#include "Types/DefaultCommand.h"

class StopShooterHeightCommand : public DefaultCommand {

public:
	StopShooterHeightCommand();
	void Initialize() override;
};