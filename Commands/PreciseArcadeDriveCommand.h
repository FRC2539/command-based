#ifndef PRECISE_ARCADE_DRIVE_COMMAND_H
#define PRECISE_ARCADE_DRIVE_COMMAND_H

#include "../CommandBase.h"

class PreciseArcadeDriveCommand : public CommandBase {

public:
	PreciseArcadeDriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	bool wasReleased;
	static bool justEnded;
};

#endif
