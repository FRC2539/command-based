#include "LowBarCrossCommandGroup.h"

#include "../SetShooterHeightDownCommandGroup.h"
#include "../AlignmentTurnCommand.h"
#include "DriveToFloorCommand.h"

#include "../../Config.h"

LowBarCrossCommandGroup::LowBarCrossCommandGroup() : CommandGroup("LowBarCrossCommandGroup")
{
	AddSequential(new SetShooterHeightDownCommandGroup());
	AddSequential(new DriveToFloorCommand(-200));
}
