#include "SafeFireCommand.h"

#include "FireCommandGroup.h"

SafeFireCommand::SafeFireCommand() {
	fireCommandGroup = new FireCommandGroup();
}

SafeFireCommand::~SafeFireCommand()
{
	delete fireCommandGroup;
}

void SafeFireCommand::Initialize() {
	if ( ! pickup->isUp())
	{
		fireCommandGroup->Start();
	}
}

void SafeFireCommand::Execute() {
}

bool SafeFireCommand::IsFinished() {
	return true;
}

void SafeFireCommand::End() {
}

void SafeFireCommand::Interrupted() {
}


