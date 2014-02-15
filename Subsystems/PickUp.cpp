#include "PickUp.h"

#include "Victor.h"
#include "DoubleSolenoid.h"
#include "DigitalInput.h"
#include "../Custom/AnalogUltrasonic.h"

#include "../Commands/PickUpCommand.h"

#include "../RobotMap.h"

PickUp::PickUp() :
	Subsystem("PickUp")
{
	motor = new Victor(PICK_UP_MOTOR_PORT);
	solenoid = new DoubleSolenoid(PICK_UP_PISTON_CLOSED_PORT, PICK_UP_PISTON_OPEN_PORT);
	ultrasonic = new AnalogUltrasonic(PICK_UP_ULTRASONIC_PORT);
	downLimitSwitch = new DigitalInput(PICK_UP_DOWN_PORT);
	upLimitSwitch = new DigitalInput(PICK_UP_UP_PORT);
}

PickUp::~PickUp() {
	delete motor;
	delete solenoid;
	delete ultrasonic;
	delete downLimitSwitch;
	delete upLimitSwitch;
}

void PickUp::InitDefaultCommand() {
	SetDefaultCommand(new PickUpCommand());
}

void PickUp::pickup(float direction)
{
	if (direction < -0.1)
	{
		direction *= .4;
		if (isDown())
		{
			direction = 0;
		}
	}
	else if (direction > 0.1 && isUp())
	{
		direction = 0;
	}
	motor->Set(direction);
}

void PickUp::open()
{
	solenoid->Set(DoubleSolenoid::kForward);
}

void PickUp::close()
{
	solenoid->Set(DoubleSolenoid::kReverse);
}

bool PickUp::isUp()
{
	return !upLimitSwitch->Get();

}

bool PickUp::isDown()
{
	return !downLimitSwitch->Get();
	
}

bool PickUp::seesBall()
{
	return (ultrasonic->getDistance() < 8);
}
