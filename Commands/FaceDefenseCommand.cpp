#include "FaceDefenseCommand.h"

#include "AlignmentTurnCommand.h"

FaceDefenseCommand::FaceDefenseCommand() :
	DefaultCommand("FaceDefense")
{
	Requires(drivetrain);

	m_faceCourtyard = new AlignmentTurnCommand(0);
	m_faceNeutralZone = new AlignmentTurnCommand(180);
}

FaceDefenseCommand::~FaceDefenseCommand()
{
	delete m_faceCourtyard;
	delete m_faceNeutralZone;
}

void FaceDefenseCommand::Initialize()
{
	double angle = drivetrain->getAngle();

	if (angle >= 90 && angle < 270)
	{
		m_currentCommand = m_faceNeutralZone;
	}
	else
	{
		m_currentCommand = m_faceCourtyard;
	}

	m_currentCommand->Start();
}

bool FaceDefenseCommand::IsFinished()
{
	return !m_currentCommand->IsRunning();
}




