#include "CommandBase.h"

CommandBase::CommandBase(const char *name, double timeout)
	: Command(name, timeout) {}

CommandBase::CommandBase(const char *name) : Command(name) {}

CommandBase::CommandBase(double timeout) : Command(timeout) {}

CommandBase::CommandBase() : Command() {}

CommandBase::~CommandBase() {
	delete drivetrain;
	delete monitor;
	delete pickuparms;
	delete shooter;
	delete oi;
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	drivetrain->ignoreEncoders();
	monitor = new Monitor();
	pickuparms = new PickupArms();
	shooter = new Shooter();

	// This subsystem must be instantiated last
	oi = new OI();
}


/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the roboRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
Monitor* CommandBase::monitor = NULL;
PickupArms* CommandBase::pickuparms = NULL;
Shooter* CommandBase::shooter = NULL;
OI* CommandBase::oi = NULL;

