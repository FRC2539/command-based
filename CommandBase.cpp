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
	
	if (shooter != NULL)
	{
		delete shooter;
	}
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	oi = new OI();
	pickup = new PickUp();
	shooter = new Shooter();
	
	std::cout << "Subsystems Initialized\n";
}

void CommandBase::Requires(Subsystem* s)
{
	std::cout << "Calling Requires()\n";
	Command::Requires(s);
}


/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the cRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
OI* CommandBase::oi = NULL;
PickUp* CommandBase::pickup = NULL;
Shooter* CommandBase::shooter = NULL;
