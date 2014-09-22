#ifndef PRECISE_ARCADE_DRIVE_COMMAND_H
#define PRECISE_ARCADE_DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class PreciseArcadeDriveCommand : public DefaultCommand {

public:
	PreciseArcadeDriveCommand();
	void Execute();

protected:
	float scaleAxis(const unsigned int axis, float max);
};

#endif
