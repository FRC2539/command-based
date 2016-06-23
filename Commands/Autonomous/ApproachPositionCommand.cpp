#include "ApproachPositionCommand.h"

#include "DriveDistanceCommandGroup.h"

ApproachPositionCommand::ApproachPositionCommand(float distance) :
	DefaultCommand("ApproachPosition"),
	m_parent(nullptr)
{
	Requires(drivetrain);

	m_speed = 200;
	if (distance < 0)
	{
		m_speed *= -1;
	}
}

void ApproachPositionCommand::Initialize()
{
	if (m_parent == nullptr)
	{
		m_parent = (DriveDistanceCommandGroup*)GetGroup();
	}

	drivetrain->setMaxSpeed(m_speed);
	drivetrain->move(0, 1, 0);
}

bool ApproachPositionCommand::IsFinished()
{
	std::vector<double> currentPositions = drivetrain->getEncoderPositions();
	if (m_speed < 0)
	{
		if (currentPositions[0] < m_parent->handoffPositions[0])
		{
			return true;
		}

		return currentPositions[1] > m_parent->handoffPositions[1];
	}

	if (currentPositions[0] > m_parent->handoffPositions[0])
	{
		return true;
	}

	return currentPositions[1] < m_parent->handoffPositions[1];
}

void ApproachPositionCommand::End()
{
	drivetrain->stop();
}
