#ifndef ZERO_GYRO_COMMAND_H
#define ZERO_GYRO_COMMAND_H

#include "Types/InstantCommand.h"

class ZeroGyroCommand : public InstantCommand {

public:
	ZeroGyroCommand();
	void Initialize();
};

#endif
