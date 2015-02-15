#include "Elevator.h"

#include <CANTalon.h>
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator"), minPosition(0), maxPosition(0)
{
	elevatorMotor = new CANTalon(RobotMap::Elevator::elevatorMotorID);
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);
	elevatorMotor->SetSensorDirection(true);
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

	if (targetPosition < elevatorMotor->GetPosition())
	{
		elevatorMotor->Set(-RobotMap::Elevator::stepSpeed);
	}
	else
	{
		elevatorMotor->Set(RobotMap::Elevator::stepSpeed);
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

void Elevator::directDrive(float percentVoltage)
{
	elevatorMotor->SetControlMode(CANSpeedController::kPercentVbus);
	elevatorMotor->Set(percentVoltage);
}

void Elevator::endDirectDrive()
{
	elevatorMotor->Set(0);
	targetPosition = elevatorMotor->GetPosition();
	elevatorMotor->SetControlMode(CANSpeedController::kSpeed);
}

int Elevator::GetPosition()
{
	return elevatorMotor->GetPosition();
}
void Elevator::SetPosition(int ElevatorPosition)
{
	elevatorMotor->SetPosition(ElevatorPosition);
}
