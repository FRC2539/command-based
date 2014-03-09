#ifndef STEP_COMMAND_H
#define STEP_COMMAND_H

#include "DefaultCommand.h"
#include <vector>

/*
 * Run a serious of commands with variable timing.
 *
 * To use override command, define a constructor that calls addCommand() for
 * each step in the sequence. On every execution of this command, the next
 * command in the sequence will be run. If you want to restart the sequence
 * before you reach the end, call the restart() method of this class.
 */

class StepCommand : public DefaultCommand {

public:
	StepCommand(const char* name);
	StepCommand();
    virtual ~StepCommand();

	void addCommand(Command* command);
	void restart();

	void Initialize();
	bool IsFinished();
	void Interrupted();

protected:
	void stopCurrentCommand();

	std::vector<Command*> m_commands;
	unsigned int m_index;
};

#endif
