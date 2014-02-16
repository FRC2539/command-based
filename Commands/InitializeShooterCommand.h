#ifndef INITIALIZE_SHOOTER_COMMAND_H
#define INITIALIZE_SHOOTER_COMMAND_H

#include "../CommandBase.h"

class InitializeShooterCommand : public CommandBase {

public:
	InitializeShooterCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
