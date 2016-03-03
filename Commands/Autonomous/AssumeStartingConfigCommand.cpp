#include "AssumeStartingConfigCommand.h"

#include "../../Config.h"

AssumeStartingConfigCommand::AssumeStartingConfigCommand()
	: InstantCommand("AssumeStartingConfig")
{
	Requires(shooter);
	Requires(pickuparms);
}

void AssumeStartingConfigCommand::Initialize()
{
	shooter->setEncoderPosition(Config::Shooter::maxHeight);
	pickuparms->setEncoderPosition(Config::PickupArms::maxHeight);
}
