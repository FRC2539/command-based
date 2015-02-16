#include "ZeroElevatorCommand.h"

ZeroElevatorCommand::ZeroElevatorCommand() : DefaultCommand("ZeroElevator") {}

void ZeroElevatorCommand::Initialize()
{
	elevator->disableSoftLimits();
}

void ZeroElevatorCommand::End()
{
    elevator->zeroElevator();
	elevator->enableSoftLimits();
}
