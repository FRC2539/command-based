#include "LowerArmCommand.h"

LowerArmCommand::LowerArmCommand() : InstantCommand("LowerArm")
{
	Requires(pickup);
}

void LowerArmCommand::Initialize()
{
	pickup->lowerArm();
	pickup->pickup(1);
}

