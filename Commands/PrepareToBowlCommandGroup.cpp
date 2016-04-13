#include "PrepareToBowlCommandGroup.h"

#include "../Config.h"

#include "SetShooterHeightCommand.h"
#include "SpinShooterCommand.h"

PrepareToBowlCommandGroup::PrepareToBowlCommandGroup() : CommandGroup("PrepareToBowl")
{
	AddParallel(new SpinShooterCommand(.4));
}
