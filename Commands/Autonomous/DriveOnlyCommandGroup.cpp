#include "DriveOnlyCommandGroup.h"

#include "../ResetCommand.h"
#include "DriveDistanceCommand.h"

DriveOnlyCommandGroup::DriveOnlyCommandGroup() : CommandGroup("DriveOnly")
{
	AddSequential(new ResetCommand());
	AddSequential(new DriveDistanceCommand(115, DriveDistanceCommand::Y, 100));
}

