#include "PrepareToBowlCommandGroup.h"

//#include "BowlingAimCommand.h"
#include "SpinShooterCommand.h"

PrepareToBowlCommandGroup::PrepareToBowlCommandGroup() : CommandGroup("PrepareToBowl")
{
	//AddParallel(new BowlingAimCommand());
	AddParallel(new SpinShooterCommand());
}
