#pragma once

#include "DefaultCommand.h"

/*
 * A command type to execute another Command, if given conditions are met.
 *
 * To use, you must override this class and do the following:
 * 1.) In the constructor, set m_command to point to a Command
 * 2.) Implement the shouldRun() method
 *
 * shouldRun will be checked every time your ConditionalCommand is started.
 */

class ConditionalCommand : public DefaultCommand {

public:
	ConditionalCommand(const char* name);
	ConditionalCommand();
	virtual ~ConditionalCommand();

	void Initialize();
	bool IsFinished();
	void Interrupted();

protected:
	virtual bool shouldRun() = 0;
	Command* m_command;
	bool m_isStarted;
};
