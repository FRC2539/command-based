#include "AutoShootingPositionCommandGroup.h"
#include "DrawBackCommandGroup.h"
#include "AutoPickUpCommand.h"
#include "AutoDriveCommand.h"
#include "Commands/WaitCommand.h"

AutoShootingPositionCommandGroup::AutoShootingPositionCommandGroup() {
	AddParallel(new AutoPickUpCommand(-1, 1));
	AddSequential(new WaitCommand(0.5));
	AddSequential(new DrawBackCommandGroup());

	AddSequential(new AutoDriveCommand(-.5678, 2));
}
