#include "Shooter.h"

#include "Victor.h"
#include "Relay.h"
#include "DigitalInput.h"

#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter")
{
	motor = new Victor(SHIFTING_GEAR_MOTOR_PORT);
	electromagnet = new Relay(SHOOTER_ELECTROMAGNET_PORT, Relay::kForwardOnly);
	downSwitch = new DigitalInput(SHOOTER_DOWNSWITCH_PORT);
}

Shooter::~Shooter()
{
	delete motor;
	delete electromagnet;
	delete downSwitch;
}

void Shooter::releaseLauncher()
{
	electromagnet->Set(Relay::kOff);
}

void Shooter::retractLauncher()
{
	motor->Set(1);
	electromagnet->Set(Relay::kOn);
}

void Shooter::runBack()
{
	motor->Set(-.75);
}

void Shooter::reset()
{
	motor->Set(0);
}

bool Shooter::isDown()
{
	return !downSwitch->Get();
}
