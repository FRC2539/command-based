#include "ApproachAngleCommand.h"

#include "TurnAngleCommandGroup.h"

ApproachAngleCommand::ApproachAngleCommand(float angle) :
	DefaultCommand("ApproachAngle"),
	m_parent(nullptr)
{
	Requires(drivetrain);

	m_direction = 1;
	if (angle < 0)
	{
		m_direction = -1;
	}
}

void ApproachAngleCommand::Initialize()
{
	if (m_parent == nullptr)
	{
		m_parent = (TurnAngleCommandGroup*)GetGroup();
	}

	drivetrain->setMaxSpeed(200);
	drivetrain->move(0, 0, m_direction);
}

bool ApproachAngleCommand::IsFinished()
{
	std::vector<double> currentPositions = drivetrain->getEncoderPositions();
	if (m_direction < 0)
	{
		if (currentPositions[0] < m_parent->handoffPositions[0])
		{
			return true;
		}

		return currentPositions[1] < m_parent->handoffPositions[1];
	}

	if (currentPositions[0] > m_parent->handoffPositions[0])
	{
		return true;
	}

	return currentPositions[1] > m_parent->handoffPositions[1];
}

void ApproachAngleCommand::End()
{
	drivetrain->stop();
}
