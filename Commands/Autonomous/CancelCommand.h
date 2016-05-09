#pragma once

#include "../Types/InstantCommand.h"

class CancelCommand : public InstantCommand {

public:
	CancelCommand(Command* cmd);
	void Initialize();

protected:
	Command* m_command;
};
