#include "PickUpArm.h"

#include "../RobotMap.h"
#include <Victor.h>
#include <DigitalInput.h>

PickUpArm::PickUpArm() : Subsystem("PickUpArm")
{
	pickupWheelsMotor = new Victor(RobotMap::PickUpArm::wheelsMotorPort);
	ballSensor = new DigitalInput(RobotMap::PickUpArm::ballSensorPort);
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
