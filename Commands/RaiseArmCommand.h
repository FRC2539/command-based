#ifndef RAISE_ARM_COMMAND_H
#define RAISE_ARM_COMMAND_H

#include "../CommandBase.h"

class RaiseArmCommand : public CommandBase {

public:
	RaiseArmCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
