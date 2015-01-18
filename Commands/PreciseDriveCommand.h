#ifndef PRECISE_DRIVE_COMMAND_H
#define PRECISE_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class PreciseDriveCommand : public DefaultCommand {

public:
	PreciseDriveCommand();
	void Initialize();
	void Execute();
	void End();
};

#endif
