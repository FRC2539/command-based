#include "AlignmentTurnCommand.h"

#include "../Config.h"

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
	drivetrain->setMaxSpeed(Config::DriveTrain::preciseModeMaxSpeed);
	SensorCommand::Initialize();
}

void AlignmentTurnCommand::End()
{
	SensorCommand::End();
}

void AlignmentTurnCommand::UsePIDOutput(double output)
{
	drivetrain->move(0, 0, output);
}

double AlignmentTurnCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}