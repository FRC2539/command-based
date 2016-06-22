#include "CalculatePositionsCommand.h"

#include "DriveDistanceCommandGroup.h"
#include "../../Config.h"

CalculatePositionsCommand::CalculatePositionsCommand(float distance)
	: InstantCommand("CalculatePositions"),
	m_distance(distance / Config::DriveTrain::encoderSensitivity),
	m_parent(nullptr)
{
	Requires(drivetrain);

	float error = 150;
	if (m_distance < 0)
	{
		error *= -1;
	}
	m_handoffDistance = m_distance - error;
}

void CalculatePositionsCommand::Initialize()
{
	if (m_parent == nullptr)
	{
		m_parent = (DriveDistanceCommandGroup*)GetGroup();
	}

	/*int sign = 1;
	m_parent->handoffPositions.clear();
	m_parent->finalPositions.clear();
	std::vector<double> currentPositions = drivetrain->getEncoderPositions();
	for (float position : currentPositions)
	{
		m_parent->handoffPositions.push_back(position + m_handoffDistance * sign);
		m_parent->finalPositions.push_back(position + m_distance * sign);

		sign = sign * -1;
	}*/
}
