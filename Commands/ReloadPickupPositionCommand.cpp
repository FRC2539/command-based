#include "ReloadPickupPositionCommand.h"

#include <Preferences.h>

#include "../Custom/DriverHUD.h"

ReloadPickupPositionCommand::ReloadPickupPositionCommand()
	: InstantCommand("ReloadPickupPosition")
{
	SetRunWhenDisabled(true);
}

void ReloadPickupPositionCommand::Initialize()
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
