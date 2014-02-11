#include "Shooter.h"
#include "../Commands/FireCommand.h"
#include "../Robotmap.h"

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
	motor->Set(-.45);
	piston->Set(DoubleSolenoid::kForward);
}

void Shooter::holdLauncher()
{
	electromagnet->Set(Relay::kOn);
	off();
	piston->Set(DoubleSolenoid::kReverse);
}

void Shooter::off()
{
	motor->Set(0);
}

bool Shooter::down()
{
	return downSwitch->Get();
}

