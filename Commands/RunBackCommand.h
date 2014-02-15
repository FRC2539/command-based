#ifndef RUNBACK_COMMAND_H
#define RUNBACK_COMMAND_H

#include "../CommandBase.h"

class RunBackCommand : public CommandBase {

public:
	RunBackCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
