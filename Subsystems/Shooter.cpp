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
}

Shooter::~Shooter() {
	delete piston;
	delete motor;
}

void Shooter::InitDefaultCommand() {
	//SetDefaultCommand(new FireCommand());
}

void Shooter::releaseLauncher()
{
	piston->Set(DoubleSolenoid::kReverse);
}

void Shooter::retractLauncher()
{
	motor->Set(-.45);

	//piston->Set(DoubleSolenoid::kForward);	
}
void Shooter::off()
{
	motor->Set(0);
}

