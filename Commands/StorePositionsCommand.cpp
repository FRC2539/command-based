#include "StorePositionsCommand.h"

StorePositionsCommand::StorePositionsCommand()
	: InstantCommand("StorePositions")
{
	SetRunWhenDisabled(true);
}

void StorePositionsCommand::Initialize()
{
	shooter->storeEncoderPosition();
}
