#include "SetShooterHeightDownCommandGroup.h"

#include <Commands/WaitCommand.h>
#include "SetShooterHeightCommand.h"
#include "StopShooterHeightCommand.h"

SetShooterHeightDownCommandGroup::SetShooterHeightDownCommandGroup()
	: CommandGroup("SetShooterHeightDownCommandGroup")
{
	AddParallel(new SetShooterHeightCommand(1));
	AddSequential(new WaitCommand(1.15));
	AddSequential(new StopShooterHeightCommand());
}
