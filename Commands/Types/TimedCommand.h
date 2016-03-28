#pragma once

#include "DefaultCommand.h"

/*
 * Perform an action for a period of time.
 *
 * You should pass a timeout value in the constructor. Then implement the
 * constructor (to Require subsystems), either Initialize or Execute (to
 * perform your actions), and End (to clean up).
 */

class TimedCommand : public DefaultCommand {

public:
	template<typename TimeUnit>
	TimedCommand(const char* name, std::chrono::duration<TimeUnit> timeout)
		: DefaultCommand(name, timeout) {};

	template<typename TimeUnit>
	TimedCommand(std::chrono::duration<TimeUnit> timeout)
		: DefaultCommand(timeout) {};

		bool IsFinished();
};
