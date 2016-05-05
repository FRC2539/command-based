#include "SetDriveTrainMaxSpeedCommand.h"

SetDriveTrainMaxSpeedCommand::SetDriveTrainMaxSpeedCommand(double Speed):
	InstantCommand("SetDriveTrainMaxSpeed"),
	m_Speed(Speed)
{
}

void SetDriveTrainMaxSpeedCommand::Initialize()
{
	drivetrain->setMaxSpeed(m_Speed);
}



