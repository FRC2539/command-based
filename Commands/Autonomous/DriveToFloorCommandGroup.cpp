#include "DriveToFloorCommandGroup.h"

#include "../AlignmentTurnCommand.h"
#include "DriveToFloorCommand.h"

DriveToFloorCommandGroup::DriveToFloorCommandGroup()
	: CommandGroup("DriveToFloor")
{
	AddSequential(new AlignmentTurnCommand(0));
	AddSequential(new DriveToFloorCommand(200));
}
