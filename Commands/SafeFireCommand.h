#ifndef SAFE_FIRE_COMMAND_H
#define SAFE_FIRE_COMMAND_H

#include "../CommandBase.h"

class SafeFireCommand : public CommandBase {

public:
	SafeFireCommand();
    virtual ~SafeFireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	Command* fireCommandGroup;

};

#endif
