#include "Motor.h"
#include "../Robotmap.h"

Motor::Motor() : Subsystem("Motor"), motor(MOTOR_PORT) {
}


void Motor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Motor::run(float speed) {
	motor.SetSpeed(speed);
}

void Motor::stop() {
	motor.SetSpeed(0);
}
