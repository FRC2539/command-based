#include "PrepareToLaunchCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SpinShooterCommand.h"

PrepareToLaunchCommandGroup::PrepareToLaunchCommandGroup() : CommandGroup("PrepareToLaunch")
{
	AddParallel(new SpinShooterCommand());
	//AddSequential(new SetShooterHeightCommand(Config::Shooter::shootingHeight));
}

