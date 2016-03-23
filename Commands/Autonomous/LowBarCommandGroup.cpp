#include "LowBarCommandGroup.h"

#include "../CrossToCourtyardCommandGroup.h"
#include "../SetShooterHeightCommand.h"

#include "../../Config.h"

LowBarCommandGroup::LowBarCommandGroup() : CommandGroup("LowBar")
{
	AddSequential(new SetShooterHeightCommand(Config::Shooter::minHeight));
	AddSequential(new CrossToCourtyardCommandGroup());
}

