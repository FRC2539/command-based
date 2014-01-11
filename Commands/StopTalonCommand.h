#ifndef STOP_TALON_COMMAND_H
#define STOP_TALON_COMMAND_H

#include "../CommandBase.h"

class StopTalonCommand : public CommandBase {
public:
	StopTalonCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
