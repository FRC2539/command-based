#include "PickUp.h"

#include "../Commands/PickUpCommand.h"
#include "../Robotmap.h"

PickUp::PickUp() :
	Subsystem("PickUp")
	{
	motor = new Victor(PICK_UP_MOTOR_PORT);
	solenoid = new DoubleSolenoid(PICK_UP_PISTON_CLOSED_PORT, PICK_UP_PISTON_OPEN_PORT);
	ultrasonic = new AnalogUltrasonic(PICK_UP_ULTRASONIC_PORT);
	//switch the closed port and open port if they need switched, might have gotten the channels wrong
}

PickUp::~PickUp() {
	delete motor;
}

void PickUp::InitDefaultCommand() {
	SetDefaultCommand(new PickUpCommand());
}

void PickUp::pickup(float direction)
{
	if(direction == 1)
	{
		motor->Set(1);
	}
	else if(direction == -1)
	{
		motor->Set(-.4);
	}
	else
	{
		motor->Set(0);
	}
}

void PickUp::open()
{
	solenoid->Set(DoubleSolenoid::kForward);
}

void PickUp::close()
{
	solenoid->Set(DoubleSolenoid::kReverse);
}

void PickUp::distancePickup(float direction)
{
	if(direction == 1 && ultrasonic->getDistance() < 7)
	{
		motor->Set(1);
	}
	else if(direction == -1)
	{
		motor->Set(-.4);
	}
	else
	{
		motor->Set(0);
	}
	
}