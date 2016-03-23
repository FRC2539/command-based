#include "AssumeStartingConfigCommand.h"

#include "../../Config.h"

AssumeStartingConfigCommand::AssumeStartingConfigCommand()
	: InstantCommand("AssumeStartingConfig")
{
	Requires(shooter);
}

void AssumeStartingConfigCommand::Initialize()
{
	shooter->setEncoderPosition(Config::Shooter::maxHeight);
}
