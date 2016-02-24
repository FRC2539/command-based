#include "AlignmentTurnCommand.h"

#include "../Config.h"
#include "../Custom/Netconsole.h"

AlignmentTurnCommand::AlignmentTurnCommand(double angle)
	: SensorCommand("AlignmentTurn", angle, 0.25, 0.002, 0)
{
	Requires(drivetrain);

	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
	setMaxOutput(1);
	setAbsoluteError(2);
}

void AlignmentTurnCommand::Initialize()
{
	Netconsole::instant("Alignment Begin", 1);
	drivetrain->setMaxSpeed(Config::DriveTrain::preciseModeMaxSpeed);
	SensorCommand::Initialize();
}

void AlignmentTurnCommand::End()
{
	Netconsole::instant("Alignment Done", 1);
	SensorCommand::End();
}

void AlignmentTurnCommand::UsePIDOutput(double output)
{
	Netconsole::print("Error", m_controller->GetAvgError());
	Netconsole::print("Target", m_controller->GetSetpoint());
	drivetrain->move(0, 0, output);
}

double AlignmentTurnCommand::ReturnPIDInput() const
{
	Netconsole::print("Current", drivetrain->getAngle());
	return drivetrain->getAngle();
}