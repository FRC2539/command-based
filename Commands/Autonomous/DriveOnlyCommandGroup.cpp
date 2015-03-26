#include "DriveOnlyCommandGroup.h"

#include "../ResetCommand.h"
#include "DriveDistanceCommand.h"

DriveOnlyCommandGroup::DriveOnlyCommandGroup() : CommandGroup("DriveOnly")
{
	AddSequential(new ResetCommand());
	AddSequential(new DriveDistanceCommand(150, DriveDistanceCommand::Y, 125));
	
}

