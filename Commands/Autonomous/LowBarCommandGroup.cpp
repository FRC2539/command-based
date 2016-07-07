#include "LowBarCommandGroup.h"

#include "AssumeStartingConfigCommand.h"
#include "../ShooterMoveCommand.h"
#include "../CrossDefenseCommand.h"
#include "TurnAngleCommandGroup.h"

#include "../GraphEncodersCommand.h"
#include <Commands/PrintCommand.h>

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
//	AddSequential(new AssumeStartingConfigCommand());
//	AddSequential(new ShooterMoveCommand(Shooter::DOWN));
//	AddSequential(new CrossDefenseCommand());

	AddParallel(new GraphEncodersCommand);
	AddSequential(new TurnAngleCommandGroup(360));
	AddSequential(new PrintCommand("Fin\n"));
}

