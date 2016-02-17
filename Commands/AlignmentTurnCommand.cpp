#include "AlignmentTurnCommand.h"

AlignmentTurnCommand::AlignmentTurnCommand(double angle)
	: SensorCommand("AlignmentTurn", angle, 0.5, 0, 0)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
	setMaxOutput(1);
	setAbsoluteError(2);
}

void AlignmentTurnCommand::UsePIDOutput(double output)
{
	drivetrain->move(0, 0, output);
}

double AlignmentTurnCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}