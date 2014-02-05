#include "CommandBase.h"

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

	if (pickup != NULL)
	{
		delete pickup;
	}

	if (aircompressor != NULL)
	{
		delete aircompressor;
		
	}
	if (shooter != NULL)
	{
		delete shooter;
	}
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	oi = new OI();
	pickup = new PickUp();
	aircompressor = new AirCompressor();
	shooter = new Shooter();
}

/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the cRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;
PickUp* CommandBase::pickup = NULL;
AirCompressor* CommandBase::aircompressor = NULL;
Shooter* CommandBase::shooter = NULL;
