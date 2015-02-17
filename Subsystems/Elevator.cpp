#include "Elevator.h"

#include <CANTalon.h>
#include <Preferences.h>
#include <cmath>

#include "../RobotMap.h"
#include "../Custom/DriveTrain/RatePIDController.h"
#include "../Custom/DriveTrain/CANTalonRatePIDSource.h"
#include "../Commands/MaintainHeightCommand.h"
#include "../Custom/Netconsole.h"

Elevator::Elevator() : Subsystem("Elevator"),
	settingsLoaded(false),
	targetPosition(-1),
	level(0),
	fuzzyLevel(true)
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

	pidLoop = new RatePIDController(
		RobotMap::Elevator::P,
		RobotMap::Elevator::I,
		RobotMap::Elevator::D,
		new CANTalonRatePIDSource(elevatorMotor),
		elevatorMotor
	);
	pidLoop->SetInputRange(
		-RobotMap::Elevator::stepSpeed,
		RobotMap::Elevator::stepSpeed
	);
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
	pidLoop->Disable();
	elevatorMotor->SetControlMode(CANSpeedController::kPosition);
	elevatorMotor->Set(elevatorMotor->GetPosition());
}

void Elevator::changeLevel(int difference)
{
	if (fuzzyLevel == true && difference < 0)
	{
		difference++;
	}
	level += difference;
	targetPosition = RobotMap::Elevator::minPosition + level * RobotMap::Elevator::stepSize;
	if (targetPosition > RobotMap::Elevator::maxPosition)
	{
		targetPosition -= RobotMap::Elevator::stepSize;
		while (targetPosition > RobotMap::Elevator::maxPosition)
		{
			level--;
			targetPosition -= RobotMap::Elevator::stepSize;
		}
		targetPosition = RobotMap::Elevator::maxPosition;
	}
	else if (targetPosition < RobotMap::Elevator::minPosition)
	{
		level = 0;
		targetPosition = RobotMap::Elevator::minPosition;
	}

	moveToward(targetPosition);

	fuzzyLevel = false;
}

void Elevator::moveToward(int height)
{
	if (height < elevatorMotor->GetPosition())
	{
		directDrive(-RobotMap::Elevator::stepSpeed);
	}
	else
	{
		directDrive(RobotMap::Elevator::stepSpeed);
	}
}

bool Elevator::onTarget()
{
	int speed = elevatorMotor->Get();
	if (speed < 0)
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
	elevatorMotor->SetControlMode(CANSpeedController::kPercentVbus);
	pidLoop->SetSetpoint(speed);
	if (pidLoop->IsEnabled() == false)
	{
		pidLoop->Enable();
	}
	Netconsole::instant<int>("Height", elevatorMotor->GetPosition());
}

void Elevator::recalculateLevel()
{
	level = convertToLevel(elevatorMotor->GetPosition());
	fuzzyLevel = true;
}

int Elevator::convertToLevel(int encoderValue)
{
	float value = encoderValue - RobotMap::Elevator::minPosition;
	value /= RobotMap::Elevator::stepSize;

	return (int)std::floor(value);
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
		level = convertToLevel(elevatorMotor->GetPosition());
		settingsLoaded = true;
		fuzzyLevel = true;
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
	fuzzyLevel = false;
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
