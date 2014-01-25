#include "CommandBase.h"

#include "Subsystems/DriveTrain.h"
#include "OI.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

CommandBase::~CommandBase() {
	if (oi != NULL)
	{
		delete oi;
	}

	if (drivetrain != NULL)
	{
		delete drivetrain;
	}
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	oi = new OI();
}

/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the cRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;
