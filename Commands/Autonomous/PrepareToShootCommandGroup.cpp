#include "PrepareToShootCommandGroup.h"
#include "../DrawBackCommandGroup.h"
#include "PickUpTimedCommand.h"
#include "DriveTimedCommand.h"
#include "Commands/WaitCommand.h"

PrepareToShootCommandGroup::PrepareToShootCommandGroup()
	: CommandGroup("PrepareToShoot")
{
	AddParallel(new PickUpTimedCommand(1, 1));
	AddParallel(new DriveTimedCommand(-.5678, 2.8));
	AddSequential(new WaitCommand(0.5));
	AddSequential(new DrawBackCommandGroup());
}
