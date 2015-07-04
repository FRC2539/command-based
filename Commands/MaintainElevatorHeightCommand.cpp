#include "MaintainElevatorHeightCommand.h"

MaintainElevatorHeightCommand::MaintainElevatorHeightCommand()
	: DefaultCommand("MaintainElevatorHeight")
{
	Requires(elevator);
}

void MaintainElevatorHeightCommand::Initialize()
{
	elevator->go(Elevator::HOLD);
}
