#include "RaiseElevatorCommand.h"

RaiseElevatorCommand::RaiseElevatorCommand()
	: InstantCommand("RaiseElevator")
{
	Requires(elevator);
}

void RaiseElevatorCommand::Initialize()
{
	elevator->changePosition(1);
}
