#include "Shooter.h"

#include "Victor.h"
#include "Relay.h"
#include "DigitalInput.h"

#include "../Commands/FireCommand.h"

#include "../RobotMap.h"
#include <iostream>

Shooter::Shooter() :
	Subsystem("Shooter")
	{
	motor = new Victor(SHIFTING_GEAR_MOTOR_PORT);
	electromagnet = new Relay(SHOOTER_ELECTROMAGNET_PORT, Relay::kForwardOnly);
	downSwitch = new DigitalInput(SHOOTER_DOWNSWITCH_PORT);
}

Shooter::~Shooter() {
	delete motor;
	delete electromagnet;
	delete downSwitch;
}

void Shooter::InitDefaultCommand() {
	//SetDefaultCommand(new FireCommand());
}

void Shooter::releaseLauncher()
{
	electromagnet->Set(Relay::kOff);
}

void Shooter::retractLauncher()
{
	motor->Set(0.8);
	electromagnet->Set(Relay::kOn);
}

void Shooter::runBack(){
	motor->Set(-.5);
}

void Shooter::reset()
{
	motor->Set(0);
}

bool Shooter::down()
{
	return !downSwitch->Get();
}
