#include "PickUpArm.h"

#include "../RobotMap.h"
#include <Victor.h>

PickUpArm::PickUpArm() : Subsystem("PickUpArm")
{
	pickupWheelsMotor = new Victor(RobotMap::PickUpArm::wheelMotorPort);
}


PickUpArm::~PickUpArm()
{
	delete pickupWheelsMotor;
}


void PickUpArm::setWheelSpeed(const float speed)
{
	pickupWheelsMotor->Set(speed);
}
