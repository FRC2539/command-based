#include "DriveDistanceCommand.h"

DriveDistanceCommand::DriveDistanceCommand(
	double distance,
	Direction direction
) : DefaultCommand("DriveDistance"),
	m_direction(direction),
	m_distance(distance)
{
	Requires(drivetrain);
}

void DriveDistanceCommand::Initialize()
{
	if (m_direction == Direction::X)
	{
		drivetrain->moveDistance(m_distance, drivetrain->DriveX);
	}
	else
	{
		drivetrain->moveDistance(m_distance, drivetrain->DriveY);
	}
}

bool DriveDistanceCommand::IsFinished()
{
	return drivetrain->doneMoving();
}

void DriveDistanceCommand::End()
{
	drivetrain->stop();
}
