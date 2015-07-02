#include "Elevator.h"

#include <CANTalon.h>
#include <Preferences.h>
#include <SmartDashboard/SmartDashboard.h>
#include <cmath>

#include "../RobotMap.h"
#include "../Commands/MaintainHeightCommand.h"

Elevator::Elevator() : Subsystem("Elevator"),
	settingsLoaded(false),
	targetPosition(-1)
{
	elevatorMotor = new CANTalon(RobotMap::Elevator::elevatorMotorID);
	elevatorMotor->SetSensorDirection(true);
	elevatorMotor->ConfigSoftPositionLimits(
		RobotMap::Elevator::maxPosition,
		RobotMap::Elevator::minPosition
	);
	elevatorMotor->DisableSoftPositionLimits();
	elevatorMotor->SetPID(
		RobotMap::Elevator::P,
		RobotMap::Elevator::I,
		RobotMap::Elevator::D
	);
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);

	maxLevel = std::ceil(
		(RobotMap::Elevator::maxPosition - RobotMap::Elevator::levelOffset) /
		(float)RobotMap::Elevator::toteHeight
	);
	recalculateLevel();
}

Elevator::~Elevator()
{
	delete elevatorMotor;
}

void Elevator::InitDefaultCommand()
{
	SetDefaultCommand(new MaintainHeightCommand());
}

void Elevator::maintainHeight()
{
	elevatorMotor->SetControlMode(CANSpeedController::kPosition);
	elevatorMotor->ClearIaccum();
	elevatorMotor->Set(elevatorMotor->GetPosition());
}

void Elevator::changeLevel(int difference)
{
	if (atExactLevel == false && difference < 0)
	{
		difference++;
	}
	level += difference;
	level = std::max(level, -1);
	level = std::min(level, maxLevel);

	moveToward(
		RobotMap::Elevator::levelOffset + level * RobotMap::Elevator::toteHeight
	);

	atExactLevel = true;
}

void Elevator::moveToward(int height)
{
	if (height < elevatorMotor->GetPosition())
	{
		directDrive(-RobotMap::Elevator::speed);
	}
	else
	{
		directDrive(RobotMap::Elevator::speed);
	}

	targetPosition = height;
}

bool Elevator::onTarget()
{
	if (direction == DOWN && targetPosition <= 0)
	{
		return elevatorMotor->IsRevLimitSwitchClosed();
	}
	else if (direction == DOWN)
	{
		return elevatorMotor->GetPosition() <= targetPosition ||
			elevatorMotor->IsRevLimitSwitchClosed();
	}
	else if (targetPosition > RobotMap::Elevator::maxPosition)
	{
		return elevatorMotor->IsFwdLimitSwitchClosed();
	}
	else
	{
		return elevatorMotor->GetPosition() >= targetPosition ||
			elevatorMotor->IsFwdLimitSwitchClosed();
	}
}

void Elevator::directDrive(float speed)
{
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);
	elevatorMotor->ClearIaccum();
	elevatorMotor->Set(speed);

	if (speed == 0)
	{
		direction = HOLD;
	}
	else if (speed < 0)
	{
		direction = DOWN;
	}
	else
	{
		direction = UP;
	}
}

void Elevator::doneMoving()
{
	directDrive(0);
	if (elevatorMotor->IsFwdLimitSwitchClosed())
	{
		if (elevatorMotor->GetPosition() < RobotMap::Elevator::maxPosition)
		{
			elevatorMotor->SetPosition(RobotMap::Elevator::maxPosition);
		}
	}
	else if (elevatorMotor->IsRevLimitSwitchClosed())
	{
		zeroElevator();
		return;
	}

	recalculateLevel();
}

void Elevator::recalculateLevel()
{
	int value = elevatorMotor->GetPosition() - RobotMap::Elevator::levelOffset;
	value += 10; // "Exact" means within 10 ticks
	int error = value % RobotMap::Elevator::toteHeight;
	if (error <= 20 && error >= 0) // Up to 10 above or 10 below
	{
		atExactLevel = true;
	}
	if (elevatorMotor->IsRevLimitSwitchClosed())
	{
		atExactLevel = true;
	}

	level = std::floor((float)value / RobotMap::Elevator::toteHeight);
	displayLevel();
}

void Elevator::loadSettings()
{
	if (settingsLoaded == true)
	{
		return;
	}

	Preferences* preferences = Preferences::GetInstance();
	if (preferences->ContainsKey("elevatorPosition"))
	{
		elevatorMotor->SetPosition(preferences->GetInt("elevatorPosition"));
		recalculateLevel();
		settingsLoaded = true;
	}
}

void Elevator::storeSettings()
{
	if (settingsLoaded == false)
	{
		return;
	}

	Preferences* preferences = Preferences::GetInstance();
	preferences->PutInt("elevatorPosition", elevatorMotor->GetPosition());
	preferences->Save();
}

void Elevator::zeroElevator()
{
	elevatorMotor->SetPosition(0);
	targetPosition = 0;
	level = -1;

	settingsLoaded = true;
	atExactLevel = true;

	GetDefaultCommand()->Cancel();
	displayLevel();
}

void Elevator::displayLevel()
{
	std::string precision = " Approximate";
	if (atExactLevel == true)
	{
		precision = " Exact";
	}
	SmartDashboard::PutString(
		"Elevator Level",
		std::to_string(level + 1) + precision
	);
}

void Elevator::displayHeight()
{
	SmartDashboard::PutNumber("Elevator Height", elevatorMotor->GetPosition());
}

void Elevator::enableSoftLimits()
{
	elevatorMotor->ConfigLimitMode(
		CANSpeedController::kLimitMode_SoftPositionLimits
	);
}

void Elevator::disableSoftLimits()
{
	elevatorMotor->DisableSoftPositionLimits();
}
