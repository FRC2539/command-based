#include "PickUp.h"

#include "Victor.h"
#include "DoubleSolenoid.h"

#include "../RobotMap.h"

PickUp::PickUp() : Subsystem("PickUp")
{
	motor = new Victor(PICK_UP_MOTOR_PORT);
	piston = new DoubleSolenoid(PICK_UP_RAISE_PORT, PICK_UP_LOWER_PORT);
}

PickUp::~PickUp()
{
	delete motor;
	delete piston;
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

