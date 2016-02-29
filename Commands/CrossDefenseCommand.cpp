#include "CrossDefenseCommand.h"

#include "../Config.h"

CrossDefenseCommand::CrossDefenseCommand() :
	SensorCommand("CrossDefense", 0, 0, 0.002, 0)
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
	counter = 0;
	crossedDefense = false;
}

bool CrossDefenseCommand::IsFinished()
{
    if (crossedDefense == true)
	{
		if (drivetrain->getDefenseState() == DriveTrain::DefenseState::Floor)
		{
			counter++;
		}
		return counter >= 10;
	}
	else if (drivetrain->getDefenseState() == DriveTrain::DefenseState::Defense)
	{
		crossedDefense = true;
		return false;
	}
}

void CrossDefenseCommand::Interrupted()
{
	DefaultCommand::Interrupted();
}

void CrossDefenseCommand::UsePIDOutput(double output)
{
	double y = std::max(1 - std::abs(output), 0.0);

	drivetrain->move(0, y, output);
}

double CrossDefenseCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}

