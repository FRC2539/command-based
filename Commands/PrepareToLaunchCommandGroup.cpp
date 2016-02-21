#include "PrepareToLaunchCommandGroup.h"

//#include "AimShooterCommand.h"
#include "SpinShooterCommand.h"

PrepareToLaunchCommandGroup::PrepareToLaunchCommandGroup() : CommandGroup("PrepareToLaunch")
{
	//AddParallel(new AimShooterCommand());
	AddParallel(new SpinShooterCommand());
}

