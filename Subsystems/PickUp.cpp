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
	motor->Set(.2 * direction);
}
