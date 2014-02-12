#ifndef AUTOMATIC_PICKUP_COMMAND_H
#define AUTOMATIC_PICKUP_COMMAND_H

#include "../CommandBase.h"

class AutomaticPickupCommand : public CommandBase {

public:
	AutomaticPickupCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
