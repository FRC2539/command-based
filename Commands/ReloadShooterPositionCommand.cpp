#include "ReloadShooterPositionCommand.h"

#include <Preferences.h>

#include "../Custom/DriverHUD.h"

ReloadShooterPositionCommand::ReloadShooterPositionCommand()
	: InstantCommand("ReloadShooterPosition")
{
	SetRunWhenDisabled(true);
}

void ReloadShooterPositionCommand::Initialize()
{
}
