#include "SetShooterHeightUpCommandGroup.h"

#include <Commands/WaitCommand.h>
#include "SetShooterHeightCommand.h"
#include "StopShooterHeightCommand.h"

SetShooterHeightUpCommandGroup::SetShooterHeightUpCommandGroup()
	: CommandGroup("SetShooterHeightUpCommandGroup")
{
	AddParallel(new SetShooterHeightCommand(-1));
	AddSequential(new WaitCommand(1.3));
	AddSequential(new StopShooterHeightCommand());
}
