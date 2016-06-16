#include "DriveDistanceCommand.h"
#include "LowBarCommandGroup.h"
#include "../../Config.h"

DriveDistanceCommand::DriveDistanceCommand(
	double distance,
	float error,
	DriveTrain::SensorMoveDirection direction
) : DefaultCommand("DriveDistance", 0.1s),
	m_direction(direction),
	m_distance(distance),
	m_error(error)
{
	Requires(drivetrain);
}

void DriveDistanceCommand::Initialize()
{
	if (((LowBarCommandGroup*)GetGroup())->positions.size() == 0)
	{
		((LowBarCommandGroup*)GetGroup())->positions = drivetrain->getEncoderPositions();
	}
	else
	{
		m_distance -= (((LowBarCommandGroup*)GetGroup())->positions[0] * Config::DriveTrain::encoderSensitivity);
	}
	drivetrain->moveDistance(m_distance, m_direction);
	m_atTargetCount = 0;
}

bool DriveDistanceCommand::IsFinished()
{
	if (IsTimedOut())
	{
		if (drivetrain->atTargetPosition(m_error))
		{

			m_atTargetCount++;
			return m_atTargetCount > 5;
		}

		m_atTargetCount = 0;
	}

	return false;
}

void DriveDistanceCommand::End()
{
	int index = 0;
	auto newPositions = drivetrain->getEncoderPositions();
	for(auto position : ((LowBarCommandGroup*)GetGroup())->positions)
	{
		position -= newPositions[index];
		index++;
	}
	drivetrain->stop();
}
