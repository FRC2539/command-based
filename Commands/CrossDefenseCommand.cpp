#include "CrossDefenseCommand.h"

#include "../Config.h"

CrossDefenseCommand::CrossDefenseCommand() :
	SensorCommand("CrossDefense", 0, .05, 0, 0)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
}

void CrossDefenseCommand::Initialize()
{
	drivetrain->setMaxSpeed(Config::DriveTrain::preciseModeMaxSpeed);
	m_target = drivetrain->getAngle();
	SensorCommand::Initialize();

	crossedDefense = false;
}

bool CrossDefenseCommand::IsFinished()
{
    if (crossedDefense == true)
	{
		return drivetrain->getDefenseState() == DriveTrain::Floor;
	}
    else if (drivetrain->getDefenseState() == DriveTrain::Defense)
	{
		crossedDefense = true;
		return false;
	}
}

void CrossDefenseCommand::UsePIDOutput(double output)
{
	drivetrain->move(0, 1, output);
}

double CrossDefenseCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}

