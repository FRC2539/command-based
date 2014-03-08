#include "PickUp.h"

#include "DoubleSolenoid.h"

#include "Victor.h"

#include "../Commands/PickUpCommand.h"

#include "../RobotMap.h"
#include <iostream>

PickUp::PickUp() :
	Subsystem("PickUp")
{
	motor = new Victor(PICK_UP_MOTOR_PORT);

	piston = new DoubleSolenoid(
	 FORWARD_DOUBLE_SOLINOID_PORT,
	 BACKWARD_DOUBLE_SOLINOID_PORT
	 );

}

PickUp::~PickUp() {
	delete motor;
	delete piston;
}

void PickUp::InitDefaultCommand() {

}

void PickUp::pickup(float direction)
{
	motor->Set(direction);
}

void PickUp::raiseArm()
{
	piston->Set(DoubleSolenoid::kForward);
}

void PickUp::lowerArm()
{
	piston->Set(DoubleSolenoid::kReverse);
}

