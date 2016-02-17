#include "DriveToFloor.h"

DriveToFloor::DriveToFloor() :
	SensorCommand("DriveToFloor", 0, .05, 0, 0)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
}

void DriveToFloor::Initialize()
{
	m_target = drivetrain->getAngle();
	SensorCommand::Initialize();
	crossedDefense = false;
	drivetrain->setMaxSpeed(300);
}

bool DriveToFloor::IsFinished()
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

void DriveToFloor::UsePIDOutput(double output)
{
	drivetrain->move(
		0,
		300,
		0
	);
}

double DriveToFloor::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}

