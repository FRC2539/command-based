#include "LowerElevatorCommand.h"

LowerElevatorCommand::LowerElevatorCommand()
	: InstantCommand("LowerElevator")
{
	Requires(elevator);
}

void LowerElevatorCommand::Initialize()
{
	elevator->changePosition(-1);
}
