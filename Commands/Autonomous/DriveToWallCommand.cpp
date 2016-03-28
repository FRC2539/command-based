#include "DriveToWallCommand.h"

#include "../../Config.h"

DriveToWallCommand::DriveToWallCommand(bool forward) :
	SensorCommand("DriveToWall", 0, 0, 0.002, 0),
	m_driveForward(forward)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
}

void DriveToWallCommand::Initialize()
{
	drivetrain->setMaxSpeed(Config::DriveTrain::preciseModeMaxSpeed);
	m_target = drivetrain->getAngle();
	SensorCommand::Initialize();
}

bool DriveToWallCommand::IsFinished()
{
	return std::abs(drivetrain->getAcceleration()) > 0.5;
}

void DriveToWallCommand::UsePIDOutput(double output)
{
	double y = std::max(1 - std::abs(output), 0.0);

	if (m_driveForward == false)
	{
		y *= -1;
	}

	drivetrain->move(0, y, output);
}

double DriveToWallCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}
