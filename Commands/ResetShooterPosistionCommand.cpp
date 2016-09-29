#include "ResetShooterPosistionCommand.h"

ResetShooterPosistionCommand::ResetShooterPosistionCommand() : InstantCommand("ResetShooterPosistionCommand")
{
	Requires(shooter);
}

void ResetShooterPosistionCommand::Initialize()
{
	shooter->zeroPivotEncoder();
}


