#pragma once

#include "Types/DefaultCommand.h"

class DefenseStateMonitorCommand : public DefaultCommand {

public:
	explicit DefenseStateMonitorCommand();
	void Execute() override;
};
