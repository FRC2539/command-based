#include "TurnAngleCommand.h"

#include "../../Config.h"

TurnAngleCommand::TurnAngleCommand(double angle)
	: PIDCommand("TurnAngle", angle, 0.5, 0, 0)
{
	Requires(drivetrain);

	setMaxOutput(1);
	setAbsoluteError(2);
}

void TurnAngleCommand::Initialize()
{
	drivetrain->setMaxSpeed(Config::DriveBase::preciseModeMaxSpeed);
	SetSetpointRelative(m_target);
}

void TurnAngleCommand::End()
{
	drivetrain->stop();
	drivetrain->setMaxSpeed(Config::DriveBase::maxSpeed);
}

void TurnAngleCommand::UsePIDOutput(double output)
{
	drivetrain->move(0, 0, output);
}

double TurnAngleCommand::ReturnPIDInput() const
{
	drivetrain->getAngle();
}
