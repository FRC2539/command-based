#ifndef PICK_UP_COMMAND_H
#define PICK_UP_COMMAND_H

#include "../CommandBase.h"
#include "../Controller/GenericController.h"

class PickUpCommand : public CommandBase {

public:
	PickUpCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	GenericController* controller;
};

#endif