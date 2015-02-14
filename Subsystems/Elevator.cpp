#include "Elevator.h"
#include <CANTalon.h>
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator"), minPosition(0), maxPosition(0)
{
	elevatorMotor = new CANTalon(RobotMap::Elevator::elevatorMotorID);
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);
	targetPosition = elevatorMotor->Get();
}

Elevator::~Elevator()
{
	delete elevatorMotor;
}

void Elevator::changePosition(int difference)
{
	targetPosition += difference * RobotMap::Elevator::stepSize;
	if (maxPosition > 0 && targetPosition > maxPosition)
	{
		targetPosition = maxPosition;
	}
	else if (minPosition > 0 && targetPosition < minPosition)
	{
		targetPosition = minPosition;
	}
	elevatorMotor->Set(difference * RobotMap::Elevator::stepSpeed);
}

bool Elevator::onTarget()
{
	int speed = elevatorMotor->Get();
	if (speed < 0)
	{
		return elevatorMotor->GetEncPosition() <= targetPosition;
	}
	else
	{
		return elevatorMotor->GetEncPosition() >= targetPosition;
	}
}

void Elevator::directDrive(float percentVoltage)
{
	elevatorMotor->SetControlMode(CANSpeedController::kPercentVbus);
	elevatorMotor->Set(percentVoltage);
}

void Elevator::endDirectDrive()
{
	elevatorMotor->Set(0);
	targetPosition = elevatorMotor->GetEncPosition();
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);
}

