#include "SetDriveTrainMaxSpeedCommand.h"

SetDriveTrainMaxSpeedCommand::SetDriveTrainMaxSpeedCommand(double Speed):
	DefaultCommand("SetDriveTrainMaxSpeed"),
	m_Speed(Speed)
{
}

void SetDriveTrainMaxSpeedCommand::Initialize()
{
	drivetrain->setMaxSpeed(m_Speed);
}



