#include "DriveDistanceCommand.h"

DriveDistanceCommand::DriveDistanceCommand(
	double distance,
	DriveTrain::SensorMoveDirection direction
) : DefaultCommand("DriveDistance"),
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
	return drivetrain->doneMoving();
}

void DriveDistanceCommand::End()
{
	drivetrain->stop();
}
