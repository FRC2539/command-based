#include "GyroCrossDefenseCommand.h"

#include "CrossToCourtyardCommandGroup.h"
#include "CrossToMiddleCommandGroup.h"

GyroCrossDefenseCommand::GyroCrossDefenseCommand() :
	InstantCommand("GyroCrossDefense")
{
	m_toCourtyard = new CrossToCourtyardCommandGroup();
	m_toNeutralZone = new CrossToMiddleCommandGroup();
}

GyroCrossDefenseCommand::~GyroCrossDefenseCommand()
{
	delete m_toCourtyard;
	delete m_toNeutralZone;
}

void GyroCrossDefenseCommand::Initialize()
{
	double angle = drivetrain->getAngle();

	if (angle >= 90 && angle < 270)
	{
		m_currentCommand = m_toNeutralZone;
	}
	else
	{
		m_currentCommand = m_toCourtyard;
	}

	m_currentCommand->Start();
}




