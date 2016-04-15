#pragma once

#include "Types/DefaultCommand.h"

class DriveBaseEncoderOnCommand : public DefaultCommand {

public:
	DriveBaseEncoderOnCommand();
	void Initialize();
	void End();
};