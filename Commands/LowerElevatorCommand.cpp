#include "LowerElevatorCommand.h"

LowerElevatorCommand::LowerElevatorCommand()
	: DefaultCommand("LowerElevator")
{
	Requires(elevator);
}

void LowerElevatorCommand::Initialize()
{
	elevator->changeLevel(-1);
}

bool LowerElevatorCommand::IsFinished()
{
	return elevator->onTarget();
}

void LowerElevatorCommand::End()
{
	elevator->directDrive(0);
}
