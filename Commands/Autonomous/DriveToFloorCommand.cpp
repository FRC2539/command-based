#include "DriveToFloorCommand.h"

#include "../../Config.h"

DriveToFloorCommand::DriveToFloorCommand(int directive) :
	SensorCommand("CrossDefense", 0, 0, 0.002, 0),
	m_directive(direction)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
}

void DriveToFloorCommand::Initialize()
{
	drivetrain->setMaxSpeed(-200);
	m_target = drivetrain->getAngle();
	SensorCommand::Initialize();
	counter = 0;
	crossedDefense = false;
}

bool DriveToFloorCommand::IsFinished()
{
    if (crossedDefense == true)
	{
		if (drivetrain->getDefenseState() == DriveTrain::DefenseState::Floor)
		{
			counter++;
		}
		return counter >= 10;
	}
	else if (drivetrain->getDefenseState() == DriveTrain::DefenseState::Down)
	{
		crossedDefense = true;
		return false;
	}
}

void DriveToFloorCommand::UsePIDOutput(double output)
{
	double y = std::max(1 - std::abs(output), 0.0);

	drivetrain->move(0, y, output);
}

double DriveToFloorCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}


