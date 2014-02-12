#ifndef PICKUP_WATCHER_COMMAND_H
#define PICKUP_WATCHER_COMMAND_H

#include "../CommandBase.h"

class Command;

class PickupWatcherCommand : public CommandBase {

public:
	PickupWatcherCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	Command* automaticPickupCommand;
};

#endif