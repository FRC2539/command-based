#include "FireCommand.h"

FireCommand::FireCommand() : InstantCommand("Fire")
{
	Requires(shooter);
}

void FireCommand::Initialize()
{
	shooter->releaseLauncher();
}
