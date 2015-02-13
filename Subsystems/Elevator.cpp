#include "Elevator.h"
#include <CANTalon.h>
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator"), minPosition(0), maxPosition(0)
{
	elevatorMotor = new CANTalon(RobotMap::Elevator::elevatorMotorID);
	elevatorMotor->SetControlMode(CANSpeedController::kPosition);
	currentPosition = elevatorMotor->Get();
}

Elevator::~Elevator()
{
	delete elevatorMotor;
}

void Elevator::changePosition(int difference)
{
	currentPosition += difference * RobotMap::Elevator::stepSize;
	if (maxPosition > 0 && currentPosition > maxPosition)
	{
		currentPosition = maxPosition;
	}
	else if (minPosition > 0 && currentPosition < minPosition)
	{
		currentPosition = minPosition;
	}
	elevatorMotor->Set(currentPosition);
}
 
void Elevator::directDrive(float percentVoltage)
{
	elevatorMotor->SetControlMode(CANSpeedController::kPercentVbus);
	elevatorMotor->Set(percentVoltage);
}

void Elevator::endDirectDrive()
{
	elevatorMotor->Set(0);
	currentPosition = elevatorMotor->GetEncPosition();
	elevatorMotor->SetControlMode(CANSpeedController::kPosition);
	elevatorMotor->Set(currentPosition);
}

