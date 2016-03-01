#include "SetPickupArmsHeightCommand.h"

SetPickupArmsHeightCommand::SetPickupArmsHeightCommand(int height) :
	InstantCommand("SetPickupArmsHeight"),
	m_height(height) {}

void SetPickupArmsHeightCommand::Initialize()
{
	pickuparms->pivotToHeight(m_height);
}

