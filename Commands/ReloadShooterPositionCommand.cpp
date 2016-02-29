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
	if (preferences->ContainsKey("pickupPosition"))
	{
		pickuparms->setEncoderPosition(preferences->GetInt("pickupPosition"));
	}
	else
	{
		DriverHUD::sendMessage("No Preference named \"pickupPosition\"");
	}
}
