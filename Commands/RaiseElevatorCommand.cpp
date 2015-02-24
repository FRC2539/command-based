#include "RaiseElevatorCommand.h"

RaiseElevatorCommand::RaiseElevatorCommand()
	: DefaultCommand("RaiseElevator")
{
	Requires(elevator);
}

void RaiseElevatorCommand::Initialize()
{
	elevator->changeLevel(1);
}

bool RaiseElevatorCommand::IsFinished()
{
	elevator->displayHeight();
	return elevator->onTarget();
}

void RaiseElevatorCommand::End()
{
	elevator->doneMoving();
}
