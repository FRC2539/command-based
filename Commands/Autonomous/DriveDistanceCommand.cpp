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
}

bool DriveDistanceCommand::IsFinished()
{
	if( IsTimedOut())
	{
		return drivetrain->doneMoving();
	}
	else 
	{
		return false;
	}
}

void DriveDistanceCommand::End()
{
	drivetrain->stop();
}
