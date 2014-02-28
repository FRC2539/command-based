#include "AutonomousCommandGroup.h"
#include "AutoShootingPositionCommandGroup.h"
#include "FireCommandGroup.h"


AutonomousCommandGroup::AutonomousCommandGroup() {
	AddSequential(new AutoShootingPositionCommandGroup());
	AddSequential(new FireCommandGroup());
}

