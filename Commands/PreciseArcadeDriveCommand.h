#ifndef PRECISE_ARCADE_DRIVE_COMMAND_H
#define PRECISE_ARCADE_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class PreciseArcadeDriveCommand : public DefaultCommand {

public:
	PreciseArcadeDriveCommand();
	void Initialize();
	void Execute();
	void End();
};

#endif
