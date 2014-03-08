#ifndef PICK_UP_COMMAND_H
#define PICK_UP_COMMAND_H

#include "../CommandBase.h"

class PickUpCommand : public CommandBase {

public:
	PickUpCommand(float d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	float direction;
};

#endif
