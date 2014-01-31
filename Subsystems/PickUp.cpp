#include "PickUp.h"
#include "../Commands/PickUpCommand.h"
#include "../Robotmap.h"

PickUp::PickUp() :
	Subsystem("PickUp")
	{
	motor = new Victor(PICK_UP_MOTOR_PORT);
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
