#pragma once

#include "Types/DefaultCommand.h"

class MonitorCommand : public DefaultCommand {

public:
	explicit MonitorCommand();
	void Execute() override;
};
