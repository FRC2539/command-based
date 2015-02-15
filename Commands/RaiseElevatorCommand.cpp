#include "RaiseElevatorCommand.h"

RaiseElevatorCommand::RaiseElevatorCommand()
	: DefaultCommand("RaiseElevator")
{
	Requires(elevator);
}

void RaiseElevatorCommand::Initialize()
{
	elevator->changePosition(1);
}

bool RaiseElevatorCommand::IsFinished()
{
	return elevator->onTarget();
}

void RaiseElevatorCommand::End()
{
	elevator->endDirectDrive();
}
