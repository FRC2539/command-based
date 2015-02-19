#include "Elevator.h"

#include <CANTalon.h>
#include <Preferences.h>
#include <cmath>

#include "../RobotMap.h"
#include "../Custom/DriveTrain/CANTalonRatePIDSource.h"
#include "../Commands/MaintainHeightCommand.h"
#include "../Custom/Netconsole.h"

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
	elevatorMotor->SetPID(
		RobotMap::Elevator::P,
		RobotMap::Elevator::I,
		RobotMap::Elevator::D
	);
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);

	maxLevel = std::ceil(
		(RobotMap::Elevator::maxPosition - RobotMap::Elevator::minPosition) /
		(float)RobotMap::Elevator::stepSize
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
	elevatorMotor->Set(elevatorMotor->GetPosition());
	Netconsole::instant<float>("Hold", elevatorMotor->GetPosition());
}

void Elevator::changeLevel(int difference)
{
	if (atExactLevel == false && difference < 0)
	{
		difference++;
	}
	level += difference;
	level = std::max(level, (unsigned)0);
	level = std::min(level, maxLevel);

	moveToward(
		RobotMap::Elevator::minPosition + level * RobotMap::Elevator::stepSize
	);

	atExactLevel = true;
}

void Elevator::moveToward(unsigned int height)
{
	height = std::max(RobotMap::Elevator::minPosition, height);
	height = std::min(RobotMap::Elevator::maxPosition, height);

	if (height < elevatorMotor->GetPosition())
	{
		directDrive(-RobotMap::Elevator::stepSpeed);
	}
	else
	{
		directDrive(RobotMap::Elevator::stepSpeed);
	}

	targetPosition = height;
}

bool Elevator::onTarget()
{
	if (direction == DOWN)
	{
		return elevatorMotor->GetPosition() <= targetPosition;
	}
	else
	{
		return elevatorMotor->GetPosition() >= targetPosition;
	}
}

void Elevator::directDrive(float speed)
{
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);
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
	Netconsole::instant<int>("Height", elevatorMotor->GetPosition());
}

void Elevator::recalculateLevel()
{
	int value = elevatorMotor->GetPosition() - RobotMap::Elevator::minPosition;
	int error = value % RobotMap::Elevator::stepSize;
	if (error < 10)
	{
		atExactLevel = true;
	}
	else
	{
		atExactLevel = (error - RobotMap::Elevator::stepSize > -10);
	}

	level = std::floor((float)value / RobotMap::Elevator::stepSize);
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
	level = 0;

	settingsLoaded = true;
	atExactLevel = true;

	GetDefaultCommand()->Cancel();
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
