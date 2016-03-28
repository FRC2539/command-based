#include "TimedCommand.h"

bool TimedCommand::IsFinished() {
	return IsTimedOut();
}
