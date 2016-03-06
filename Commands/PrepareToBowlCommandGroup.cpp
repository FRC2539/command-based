#include "PrepareToBowlCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SetPickupArmsHeightCommand.h"
#include "SpinShooterCommand.h"

PrepareToBowlCommandGroup::PrepareToBowlCommandGroup() : CommandGroup("PrepareToBowl")
{
	//AddParallel(new SetPickupArmsHeightCommand(Config::PickupArms::maxHeight));
	AddParallel(new SpinShooterCommand());
}
