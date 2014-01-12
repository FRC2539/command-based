#include "CommandBase.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}


void CommandBase::init() {
	oi = new OI();
}

/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the cRIO
 */
OI* CommandBase::oi = NULL;
