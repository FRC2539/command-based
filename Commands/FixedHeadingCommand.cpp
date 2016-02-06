#include "FixedHeadingCommand.h"

FixedHeadingCommand::FixedHeadingCommand() :
	SensorCommand("FixedHeading", 0, .05, 0, 0)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
}

void FixedHeadingCommand::Initialize()
{
	m_target = drivetrain->getAngle();
	SensorCommand::Initialize();
}

bool FixedHeadingCommand::IsFinished()
{
	return false;
}

void FixedHeadingCommand::UsePIDOutput(double output)
{
	drivetrain->move(
		0,
		oi->getAxisValue(logicalAxes::DriveY),
		output
	);
}

double FixedHeadingCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}


