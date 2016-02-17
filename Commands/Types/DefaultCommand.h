#pragma once

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
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};
