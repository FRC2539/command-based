#include "CommandBase.h"

CommandBase::CommandBase(const char *name, double timeout)
	: Command(name, timeout) {}

CommandBase::CommandBase(const char *name) : Command(name) {}

CommandBase::CommandBase(double timeout) : Command(timeout) {}

CommandBase::CommandBase() : Command() {}

CommandBase::~CommandBase() {
	if (oi != NULL)
	{
		delete oi;
	}

	if (drivetrain != NULL)
	{
		delete drivetrain;
	}

	if (aircompressor != NULL)
	{
		delete aircompressor;
	}

	if (pickuparm != NULL)
	{
		delete  pickuparm;
	}
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	pickuparm = new PickUpArm();
#ifdef ENABLE_AIR_COMPRESSOR
	aircompressor = new AirCompressor();
#endif
	oi = new OI();
}


/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the cRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;
AirCompressor* CommandBase::aircompressor = NULL;
PickUpArm* CommandBase::pickuparm = NULL;
