#include "SetElevatorCommand.h"

SetElevatorCommand::SetElevatorCommand(int target)
	: DefaultCommand("SetElevator"), targetHeight(target)
{
	Requires(elevator);
}

void SetElevatorCommand::Initialize()
{
	elevator->moveToward(targetHeight);
}

bool SetElevatorCommand::IsFinished()
{
	elevator->displayHeight();
	return elevator->onTarget();
}

void SetElevatorCommand::End()
{
	elevator->doneMoving();
}

