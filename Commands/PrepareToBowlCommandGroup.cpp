#include "PrepareToBowlCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SetPickupArmsHeightCommand.h"
#include "SpinShooterCommand.h"

PrepareToBowlCommandGroup::PrepareToBowlCommandGroup() : CommandGroup("PrepareToBowl")
{
	AddParallel(new SpinShooterCommand());
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
	AddSequential(new SetPickupArmsHeightCommand(Config::PickupArms::maxHeight));
}
