#ifndef PRECISE_DRIVE_COMMAND_H
#define PRECISE_DRIVE_COMMAND_H

#include "DriveCommand.h"

class PreciseDriveCommand : public DriveCommand {

public:
	PreciseDriveCommand();
	void Initialize();
	void End();
};

#endif
