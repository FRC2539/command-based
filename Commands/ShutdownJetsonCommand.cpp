#include "ShutdownJetsonCommand.h"

#include <networktables/NetworkTable.h>

ShutdownJetsonCommand::ShutdownJetsonCommand()
	: InstantCommand("ShutdownJetson")
{
	SetRunWhenDisabled(true);
}

void ShutdownJetsonCommand::Initialize()
{
	std::shared_ptr<NetworkTable> targetInfo;
	targetInfo = NetworkTable::GetTable("cameraTarget");

	targetInfo->PutBoolean("shutdownJetson", true);
}
