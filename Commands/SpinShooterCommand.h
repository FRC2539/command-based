#pragma once

#include "Types/DefaultCommand.h"

class SpinShooterCommand : public DefaultCommand {

public:
	explicit SpinShooterCommand();
	void Initialize() override;
	bool IsFinished() override;
};
