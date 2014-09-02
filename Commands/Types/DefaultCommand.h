#ifndef DEFAULT_COMMAND_H
#define DEFAULT_COMMAND_H

#include "../../CommandBase.h"

/*
 * A basic type that should be used as the base class for all other Commands
 *
 * It provides default versions of all of the pure virtual Command methods
 *	- Initialize: does nothing
 *	- Execute: does nothing
 *	- IsFinished: returns false (never finishes naturally)
 *	- End: does nothing
 *	- Interrupted: calls End()
 *
 * Override these to suit your needs.
 */

class DefaultCommand : public CommandBase {

public:
	DefaultCommand(const char* name, double timeout);
	DefaultCommand(const char* name);
	DefaultCommand(double timeout);
	DefaultCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
