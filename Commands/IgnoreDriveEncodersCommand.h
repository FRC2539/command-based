#pragma once

#include "Types/DefaultCommand.h"

class IgnoreDriveEncodersCommand : public DefaultCommand {

public:
	IgnoreDriveEncodersCommand();
	void Initialize();
	void End();
};