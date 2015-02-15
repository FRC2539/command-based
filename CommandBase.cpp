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
	#if defined(MECANUM_DRIVE)
		drivetrain = new MecanumDriveTrain();
	#elif defined(ARCADE_DRIVE)
		drivetrain = new ArcadeDriveTrain();
	#endif
	elevator = new Elevator();
	tines = new Tines();
	oi = new OI();
}


/* Each subsystem must be initially set to NULL in order for the static symbols
 * to be available on the roboRIO
 */
#if defined(MECANUM_DRIVE)
	MecanumDriveTrain* CommandBase::drivetrain = NULL;
#elif defined(ARCADE_DRIVE)
	ArcadeDriveTrain* CommandBase::drivetrain = NULL;
#endif
Elevator* CommandBase::elevator = NULL;
Tines* CommandBase::tines = NULL;
OI* CommandBase::oi = NULL;
