#ifndef LOWER_ARM_COMMAND_H
#define LOWER_ARM_COMMAND_H

#include "../CommandBase.h"

class LowerArmCommand : public CommandBase {

public:
	LowerArmCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
