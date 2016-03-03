#include "SetPickupArmsHeightCommand.h"

SetPickupArmsHeightCommand::SetPickupArmsHeightCommand(int height) :
	DefaultCommand("SetPickupArmsHeight"),
	m_height(height)
{
	Requires(pickuparms);
}

void SetPickupArmsHeightCommand::Initialize()
{
	pickuparms->pivotToHeight(m_height);
}

bool SetPickupArmsHeightCommand::IsFinished()
{
	return std::abs(pickuparms->getHeight() - m_height) < 30;
}

void SetPickupArmsHeightCommand::End()
{
	pickuparms->storeEncoderPosition();
}
