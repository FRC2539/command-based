#include "Shooter.h"

#include "Victor.h"
#include "DoubleSolenoid.h"
#include "Relay.h"
#include "DigitalInput.h"

#include "../Commands/FireCommand.h"

#include "../RobotMap.h"
#include <iostream>

Shooter::Shooter() :
	Subsystem("Shooter")
	{
	piston = new DoubleSolenoid(
		SHIFTING_GEAR_REVERSE_PISTON_PORT,
		SHIFTING_GEAR_FORWARD_PISTON_PORT
	);
	motor = new Victor(SHIFTING_GEAR_MOTOR_PORT);
	electromagnet = new Relay(SHOOTER_ELECTROMAGNET_PORT, Relay::kForwardOnly);
	downSwitch = new DigitalInput(SHOOTER_DOWNSWITCH_PORT);
}

Shooter::~Shooter() {
	delete piston;
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
	off();
}

void Shooter::retractLauncher()
{
	motor->Set(-0.60);
	piston->Set(DoubleSolenoid::kForward);
	electromagnet->Set(Relay::kOn);
}
void Shooter::holdLauncher()
{
	off();
	piston->Set(DoubleSolenoid::kReverse);
}

void Shooter::off()
{
	motor->Set(0);
	piston->Set(DoubleSolenoid::kOff);
}

bool Shooter::down()
{
	return !downSwitch->Get();
}

void Shooter::runBack(){
	motor->Set(.5);
}
