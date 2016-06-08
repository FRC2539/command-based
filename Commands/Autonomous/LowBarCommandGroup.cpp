#include "LowBarCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../ShooterMoveCommand.h"
#include "../CrossDefenseCommand.h"
#include "DriveDistanceCommand.h"
#include "ChangeSpeedCommand.h"
#include "../GraphEncodersCommand.h"
#include "../SetShooterHeightCommand.h"
#include <Commands/PrintCommand.h>

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
//	AddSequential(new AssumeStartingConfigCommand());
//	AddSequential(new ShooterMoveCommand(Shooter::DOWN));
	AddParallel(new GraphEncodersCommand);
	AddSequential(new PrintCommand("Begin\n"));
	AddSequential(new DriveDistanceCommand(24));
	AddSequential(new PrintCommand("End\n"));
	AddSequential(new SetShooterHeightCommand(1000));
	AddSequential(new SetShooterHeightCommand(0));

//	AddSequential(new CrossDefenseCommand());
//	AddSequential(new DriveDistanceCommand(24));
}

