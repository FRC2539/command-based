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
	Preferences* preferences = Preferences::GetInstance();
	if (preferences->ContainsKey("shooterPosition"))
	{
		shooter->setEncoderPosition(preferences->GetInt("shooterPosition"));
	}
	else
	{
		DriverHUD::sendMessage("No Preference named \"shooterPosition\"");
	}
}
