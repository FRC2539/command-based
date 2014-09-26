#include "PickUpArm.h"

#include "../RobotMap.h"
#include <Victor.h>
#include <DigitalInput.h>

PickUpArm::PickUpArm() : Subsystem("PickUpArm")
{
	pickupWheelsMotor = new Victor(RobotMap::PickUpArm::wheelMotorPort);
	ballSensor = new DigitalInput(RobotMap::PickUpArm::hasBallSensorPort);
}


PickUpArm::~PickUpArm()
{
	delete pickupWheelsMotor;
}


void PickUpArm::setWheelSpeed(const float speed)
{
	pickupWheelsMotor->Set(speed);
}

bool PickUpArm::hasBall()
{
	return ballSensor->Get(); 
}
