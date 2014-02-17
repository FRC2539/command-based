#ifndef RESET_COMMAND_H
#define RESET_COMMAND_H

#include "../CommandBase.h"

class ResetCommand : public CommandBase {

public:
	ResetCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
