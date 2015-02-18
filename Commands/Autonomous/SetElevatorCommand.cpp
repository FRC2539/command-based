#include "SetElevatorCommand.h"
#include "../../Custom/Netconsole.h"

SetElevatorCommand::SetElevatorCommand(int target)
	: DefaultCommand("SetElevator"), targetHeight(target)
{
	Requires(elevator);
}

void SetElevatorCommand::Initialize()
{
	elevator->moveToward(targetHeight);
	Netconsole::instant<int>("Target", targetHeight);
}

bool SetElevatorCommand::IsFinished()
{
	return elevator->onTarget();
}

void SetElevatorCommand::End()
{
	elevator->directDrive(0);
	elevator->recalculateLevel();
}

