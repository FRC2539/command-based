#pragma once

#include "Types/DefaultCommand.h"

class CameraMonitorCommand : public DefaultCommand {

public:
	explicit CameraMonitorCommand();
	void Execute() override;
};
