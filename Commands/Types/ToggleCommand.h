#ifndef TOGGLE_COMMAND_H
#define TOGGLE_COMMAND_H

#include "InstantCommand.h"

/*
 * Start or stop a command.
 *
 * This function is useful if you want a command to be started and interrupted
 * by the same event. Pass in any command to the constructor, and it will be
 * started on the first execution of this command and interrupted on the next.
 *
 * Note that if the passed command ends in some way other than this command
 * ending it, the passed command will be started on the second execution,
 * instead of being interrupted.
 */

class ToggleCommand : public InstantCommand {

public:
	ToggleCommand(const char* name, Command* command);
	ToggleCommand(Command* command);\
    virtual ~ToggleCommand();
	void Initialize();

protected:
	Command* m_command;
};

#endif
