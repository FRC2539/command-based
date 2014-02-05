#include "Shooter.h"
#include "../Commands/FireCommand.h"
#include "../Robotmap.h"
#include SHIFTING_GEAR_PISTON_MODULE

Shooter::Shooter() :
	Subsystem("Shooter")
	{
	piston = new DoubleSolenoid(
		SHIFTING_GEAR_PISTON_MODULE,
		SHIFTING_GEAR_PISTON_PORT
	);
	motor = new Victor(SHIFTING_GEAR_MOTOR_MODULE, SHIFTING_GEAR_MOTOR_PORT);
}

Shooter::~Shooter() {
	delete piston;
	delete motor;
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShooterCommand());
}

void Shooter::releaseLauncher()
{
	piston->Set(DoubleSolenoid::kReverse);
}

void Shooter::retractLauncher()
{

}
