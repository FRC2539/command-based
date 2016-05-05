#pragma once

#include "Types/InstantCommand.h"

class DriveBaseEncoderOffCommand : public InstantCommand {

public:
	DriveBaseEncoderOffCommand();
	void Initialize();
};