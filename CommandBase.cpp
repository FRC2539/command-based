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
	
	if (shooter != NULL)
	{
		delete shooter;
	}

	if (aircompressor != NULL)
	{
		delete aircompressor;
	}
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	shooter = new Shooter();
	aircompressor = new AirCompressor();

	// Instantiate OI last because its constructor uses the other subsystems
	oi = new OI();
}


/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the cRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;
Shooter* CommandBase::shooter = NULL;
AirCompressor* CommandBase::aircompressor = NULL;
