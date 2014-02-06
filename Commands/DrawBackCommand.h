#ifndef DRAWBACK_COMMAND_H
#define DRAWBACK_COMMAND_H

#include "../CommandBase.h"
#include "../Controller/GenericController.h"

class DrawBackCommand : public CommandBase {

public:
	DrawBackCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	GenericController* controller;
};

#endif
