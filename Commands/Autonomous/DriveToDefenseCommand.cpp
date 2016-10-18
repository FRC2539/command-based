#include "DriveToDefenseCommand.h"

#include "../../Config.h"

DriveToDefenseCommand::DriveToDefenseCommand() :
	SensorCommand("DriveToDefense", 0, 0, 0.002, 0)
{
	Requires(drivetrain);
	GetPIDController()->SetContinuous();
	setInputRange(0, 360);
}

void DriveToDefenseCommand::Initialize()
{
	drivetrain->setMaxSpeed(375);
	m_target = drivetrain->getAngle();
	SensorCommand::Initialize();
}

bool DriveToDefenseCommand::IsFinished()
{
	return drivetrain->getDefenseState() == DriveTrain::DefenseState::Up;
}

void DriveToDefenseCommand::UsePIDOutput(double output)
{
	double y = std::max(1 - std::abs(output), 0.0);

	drivetrain->move(0, -y, output);
}

double DriveToDefenseCommand::ReturnPIDInput() const
{
	return drivetrain->getAngle();
}

