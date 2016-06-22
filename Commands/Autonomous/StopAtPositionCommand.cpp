#include "StopAtPositionCommand.h"

#include "DriveDistanceCommandGroup.h"

StopAtPositionCommand::StopAtPositionCommand() : DefaultCommand("StopAtPosition", 0.1s)
{
	Requires(drivetrain);
}

void StopAtPositionCommand::Initialize()
{
	if (m_parent == nullptr)
	{
		m_parent = (DriveDistanceCommandGroup*)GetGroup();
	}

	drivetrain->setEncoderTargets(m_parent->finalPositions);
}

bool StopAtPositionCommand::IsFinished()
{
	if (IsTimedOut())
	{
		if (drivetrain->atTargetPosition())
		{

			m_atTargetCount++;
			return m_atTargetCount > 5;
		}

		m_atTargetCount = 0;
	}

	return false;
}

void StopAtPositionCommand::End()
{
	drivetrain->stop();
}
