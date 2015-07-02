#include "CommandBase.h"\

#include "RobotMap.h"

CommandBase::CommandBase(const char *name, double timeout)
	: Command(name, timeout) {}

CommandBase::CommandBase(const char *name) : Command(name) {}

CommandBase::CommandBase(double timeout) : Command(timeout) {}

CommandBase::CommandBase() : Command() {}

CommandBase::~CommandBase() {
	delete drivetrain;
	delete oi;
}

void CommandBase::init() {
	drivetrain = new DriveTrain();
	elevator = new Elevator();
	tines = new Tines();
	oi = new OI();
}


/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the roboRIO
 */
DriveTrain* CommandBase::drivetrain = NULL;
Elevator* CommandBase::elevator = NULL;
Tines* CommandBase::tines = NULL;
OI* CommandBase::oi = NULL;
