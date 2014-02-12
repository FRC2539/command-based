#include "PickupWatcherCommand.h"

#include "AutomaticPickupCommand.h"

PickupWatcherCommand::PickupWatcherCommand() {
	automaticPickupCommand = new AutomaticPickupCommand();
}

void PickupWatcherCommand::Initialize() {
}

void PickupWatcherCommand::Execute() {
	if (pickup->isDown() && pickup->seesBall())
	{
		automaticPickupCommand->Start();
	}
}

bool PickupWatcherCommand::IsFinished() {
	return false;
}

void PickupWatcherCommand::End() {
}

void PickupWatcherCommand::Interrupted() {
}


