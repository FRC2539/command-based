#pragma once

#include <chrono>
#include "../../CommandBase.h"

// This allows specifying units like 5min or 500ms for timeouts
using namespace std::chrono_literals;

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

protected:
	template<typename TimeUnit>
	static double inSeconds(std::chrono::duration<TimeUnit> timeout)
	{
		std::chrono::milliseconds ms;
		ms = std::chrono::duration_cast<std::chrono::milliseconds>(timeout);
		return ms.count() / 1000.0;
	};

public:
	template<typename TimeUnit>
	DefaultCommand(const char* name, std::chrono::duration<TimeUnit> timeout)
		: CommandBase(name, inSeconds(timeout)) {};

	DefaultCommand(const char* name);

	template<typename TimeUnit>
	DefaultCommand(std::chrono::duration<TimeUnit> timeout)
		: CommandBase(inSeconds(timeout)) {};

	DefaultCommand();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};
