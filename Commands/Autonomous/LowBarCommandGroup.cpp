#include "LowBarCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../ShooterMoveCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommandGroup.h"

#include "../GraphEncodersCommand.h"
#include <Commands/PrintCommand.h>

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
//	AddSequential(new AssumeStartingConfigCommand());
//	AddSequential(new ShooterMoveCommand(Shooter::DOWN));
//	AddSequential(new CrossDefenseCommand());

	AddParallel(new GraphEncodersCommand);
	AddSequential(new PrintCommand("Begin\n"));
	AddSequential(new DriveDistanceCommandGroup(24));
	AddSequential(new PrintCommand("End\n"));
}

