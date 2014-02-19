#include "AutoShootingPositionCommandGroup.h"
#include "DrawBackCommandGroup.h"
#include "AutoPickUpCommand.h"
#include "AutoDriveCommand.h"
#include "Commands/WaitCommand.h"

AutoShootingPositionCommandGroup::AutoShootingPositionCommandGroup() {
	AddParallel(new AutoPickUpCommand(-.4, 1));
	AddParallel(new AutoDriveCommand(-.5678, 2));
	AddSequential(new WaitCommand(0.5));
	//AddSequential(new DrawBackCommandGroup());
}

