#pragma once

#include "DefaultCommand.h"

/*
 * A command that performs some instantaneous action and then stops.
 *
 * When you override this class, you only need to implement the constructor (to
 * Require subsystems) and Initialize (to perform your instantaneous action).
 */

class InstantCommand : public DefaultCommand {

public:
	InstantCommand(const char* name);
	InstantCommand();
	bool IsFinished();
};
