#include "TurnAngleCommand.h"

#include <PIDController.h>
#include "../../RobotMap.h"

TurnAngleCommand::TurnAngleCommand(double angle)
	: DefaultCommand("TurnAngle"),
	m_angle(angle)
{
	Requires(drivetrain);
	pidLoop = new PIDController(0.01, 0, 0, drivetrain, drivetrain);
	pidLoop->SetAbsoluteTolerance(2);
}

void TurnAngleCommand::Initialize()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::preciseModeMaxSpeed);
	drivetrain->setPIDMode(drivetrain->Rotate);
	pidLoop->SetSetpoint(drivetrain->PIDGet() + m_angle);
	pidLoop->Enable();
}

bool TurnAngleCommand::IsFinished()
{
	return pidLoop->OnTarget();
}

void TurnAngleCommand::End()
{
	pidLoop->Disable();
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}
