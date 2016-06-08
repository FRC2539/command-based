#include "DriveDistanceCommand.h"

DriveDistanceCommand::DriveDistanceCommand(
	double distance,
	DriveTrain::SensorMoveDirection direction
) : DefaultCommand("DriveDistance", 0.1s),
	m_direction(direction),
	m_distance(distance)
{
	Requires(drivetrain);
}

void DriveDistanceCommand::Initialize()
{
	drivetrain->moveDistance(m_distance, m_direction);
	m_atTargetCount = 0;
}

bool DriveDistanceCommand::IsFinished()
{
	if (IsTimedOut())
	{
		if (drivetrain->atTargetPosition())
		{

			m_atTargetCount++;
			return m_atTargetCount > 5;
		}
	}

	return false;
}

void DriveDistanceCommand::End()
{
	drivetrain->stop();
}
