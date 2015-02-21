#include "MaintainHeightCommand.h"

MaintainHeightCommand::MaintainHeightCommand()
	: DefaultCommand("MaintainHeight")
{
	Requires(elevator);
}

void MaintainHeightCommand::Initialize()
{
	elevator->maintainHeight();
	elevator->displayHeight();
}
