#include "StorePositionsCommandGroup.h"

#include <Commands/WaitCommand.h>
#include "StorePositionsCommand.h"

StorePositionsCommandGroup::StorePositionsCommandGroup()
	: CommandGroup("StorePositions")
{
	AddSequential(new WaitCommand(10));
	AddSequential(new StorePositionsCommand());
}
