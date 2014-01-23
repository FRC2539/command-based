#ifndef ARCADE_DRIVE_COMMAND_H
#define ARCADE_DRIVE_COMMAND_H

#include "../CommandBase.h"
#include "../Controller/GenericController.h"

class ArcadeDriveCommand : public CommandBase {

public:
	ArcadeDriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	GenericController* controller;
};

#endif
