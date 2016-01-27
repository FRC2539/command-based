#pragma once

#include "DefaultCommand.h"
#include <vector>

/*
 * Run a cycle of commands, one per execution.
 *
 * You can use this class in two ways: (1) By overriding it and making your
 * own class with a constructor that has a sequence of addCommand() calls or (2)
 * by creating an instance of this class directly and calling addCommand() on
 * that instance. The first is preferred, for readability. Commands are run in
 * the order they were added.
 *
 * If you need to restart the sequence of commands in the middle of a sequence
 * call the restart() method on your instance.
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
