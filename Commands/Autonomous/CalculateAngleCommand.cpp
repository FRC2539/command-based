#include "CalculateAngleCommand.h"

#include "TurnAngleCommandGroup.h"
#include "../../Config.h"

CalculateAngleCommand::CalculateAngleCommand(float angle)
	: InstantCommand("CalculateAngle"),
	m_distance(angle * Config::DriveTrain::encoderTicksPerDegree),
	m_parent(nullptr)
{
	Requires(drivetrain);

	float error = 100;
	if (m_distance < 0)
	{
		error *= -1;
	}
	m_handoffDistance = m_distance - error;
}

void CalculateAngleCommand::Initialize()
{
	if (m_parent == nullptr)
	{
		m_parent = (TurnAngleCommandGroup*)GetGroup();
	}

	m_parent->handoffPositions.clear();
	m_parent->finalPositions.clear();
	std::vector<double> currentPositions = drivetrain->getEncoderPositions();
	for (float position : currentPositions)
	{
		m_parent->handoffPositions.push_back(position + m_handoffDistance);
		m_parent->finalPositions.push_back(position + m_distance);
	}
}
