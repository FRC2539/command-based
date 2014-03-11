#include "RaiseArmCommand.h"

RaiseArmCommand::RaiseArmCommand() : InstantCommand("RaiseArm")
{
	Requires(pickup);
}

void RaiseArmCommand::Initialize()
{
	pickup->raiseArm();
}

