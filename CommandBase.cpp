#include "CommandBase.h"\

#include "RobotMap.h"

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
}

void CommandBase::init() {
	#if defined(MECANUM_DRIVE)
		drivetrain = new MecanumDriveTrain();
	#elif defined(ARCADE_DRIVE)
		drivetrain = new ArcadeDriveTrain();
	#endif
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
OI* CommandBase::oi = NULL;
