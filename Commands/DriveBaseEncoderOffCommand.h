#pragma once

#include "Types/DefaultCommand.h"

class DriveBaseEncoderOffCommand : public DefaultCommand {

public:
	DriveBaseEncoderOffCommand();
	void Initialize();
	void End();
};