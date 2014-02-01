#ifndef PRECISE_ARCADE_DRIVE_COMMAND_H
#define PRECISE_ARCADE_DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "../Controller/GenericController.h"
#include <iostream>

class PreciseArcadeDriveCommand : public CommandBase {

public:
	PreciseArcadeDriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	GenericController* controller;
	bool wasReleased;
	static bool justEnded;
};

#endif
