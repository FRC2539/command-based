#ifndef ARCADE_DRIVE_COMMAND_H
#define ARCADE_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class ArcadeDriveCommand : public DefaultCommand {

public:
	ArcadeDriveCommand();
	void Execute();
};

#endif
