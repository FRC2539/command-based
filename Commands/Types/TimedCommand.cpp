#include "TimedCommand.h"

TimedCommand::TimedCommand(const char* name, double timeout)
	: DefaultCommand(name, timeout) {}
TimedCommand::TimedCommand(double timeout) : DefaultCommand(timeout) {}

bool TimedCommand::IsFinished() {
	return IsTimedOut();
}
