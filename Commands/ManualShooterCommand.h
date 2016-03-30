#pragma once

#include "Types/DefaultCommand.h"

class ManualShooterCommand : public DefaultCommand {

public:
	ManualShooterCommand(float power);
	void Initialize();
	//void Execute();
	void End();
	float voltage;
};