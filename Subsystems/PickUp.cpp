#include "PickUp.h"

#include "Victor.h"
#include "DigitalInput.h"
#include "../Custom/AnalogUltrasonic.h"

#include "../Commands/PickUpCommand.h"

#include "../RobotMap.h"
#include <iostream>

PickUp::PickUp() :
	Subsystem("PickUp")
{
	motor = new Victor(PICK_UP_MOTOR_PORT);
	ultrasonic = new AnalogUltrasonic(PICK_UP_ULTRASONIC_PORT);
	downLimitSwitch = new DigitalInput(PICK_UP_DOWN_PORT);
	upLimitSwitch = new DigitalInput(PICK_UP_UP_PORT);
}

PickUp::~PickUp() {
	delete motor;
	delete ultrasonic;
	delete downLimitSwitch;
	delete upLimitSwitch;
}

void PickUp::InitDefaultCommand() {
	SetDefaultCommand(new PickUpCommand());
}

void PickUp::pickup(float direction)
{
	/*if (ticks % 50 == 0)
	{
	std::cout << "ultrasonic: " << ultrasonic->getDistance() <<"\n";
	std::cout << "ultrasonic voltage: " << ultrasonic->GetVoltage() <<"\n";
	std::cout << "direction: " << direction << "\n";
	}
	ticks++;*/
	if (direction < -0.1)
	{
		direction *= .4;
		if (isDown())
		{
			direction = 0;
		}
	}

	direction *= -1;
	
	motor->Set(direction);
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
