#include "TurnAngleCommand.h"

#include "../../RobotMap.h"

TurnAngleCommand::TurnAngleCommand(double angle)
	: PIDCommand("TurnAngle", 0.5, 0, 0),
	m_angle(angle)
{
	Requires(drivetrain);

	setMaxOutput(.25);
	setAbsoluteError(2);
}

void TurnAngleCommand::Initialize()
{
	SetSetpointRelative(m_angle);
}

void TurnAngleCommand::End()
{
	drivetrain->stop();
}

void TurnAngleCommand::UsePIDOutput(double output)
{
	drivetrain->move(0, 0, output);
}

double TurnAngleCommand::ReturnPIDInput()
{
	drivetrain->getAngle();
}
