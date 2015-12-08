#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class DriveCommand : public DefaultCommand {

public:
	DriveCommand(const char* name="Drive");
	void Execute();
};

#endif
