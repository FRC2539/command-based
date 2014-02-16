#include "UnblockShooterCommand.h"

UnblockShooterCommand::UnblockShooterCommand() {
	Requires(pickup);
}

void UnblockShooterCommand::Initialize() {
	wasBlocked = pickup->isUp();
	if (wasBlocked)
	{
		pickup->pickup(-1);
		SetTimeout(0.25);
	}
}

void UnblockShooterCommand::Execute() {
}

bool UnblockShooterCommand::IsFinished() {
	if (wasBlocked)
	{
		return IsTimedOut();
	}
	return true;
}

void UnblockShooterCommand::End() {
	if (wasBlocked)
	{
		pickup->pickup(0);
	}
	pickup->open();
}

void UnblockShooterCommand::Interrupted() {
}


