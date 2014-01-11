#include "Talon.h"
#include "../Robotmap.h"

TalonSystem::TalonSystem() : Subsystem("TalonSystem"), motor(TALON_PORT) {
}

void TalonSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void TalonSystem::run(float speed) {
	motor.SetSpeed(speed);
}

void TalonSystem::stop() {
	motor.SetSpeed(0);
}
