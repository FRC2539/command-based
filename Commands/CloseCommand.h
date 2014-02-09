#ifndef CLOSE_COMMAND_H
#define CLOSE_COMMAND_H

#include "../CommandBase.h"

class CloseCommand : public CommandBase {

public:
	CloseCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
