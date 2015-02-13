#include "Elevator.h"
#include <CANTalon.h>
#include "../RobotMap.h"

Elevator::Elevator() : Subsystem("Elevator")
{
	elevatorMotor = new CANTalon(RobotMap::Elevator::ElevatormotorID);
	elevatorMotor->SetControlMode(CANSpeedController::kPosition);
}

Elevator::~Elevator()
{
	delete elevatorMotor;
}

void Elevator::InitDefaultCommand()
{
}

void Elevator::changePosition(int difference)
{
	elevatorMotor->SetPosition(elevatorMotor->GetPosition() + difference * RobotMap::Elevator::elevatorStepSize);
}
 


