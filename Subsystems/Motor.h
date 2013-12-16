#ifndef MOTOR_H
#define MOTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Motor: public Subsystem {
protected:
	Victor motor;
	
public:
	Motor();
	void InitDefaultCommand();
	
	void run(float speed);
	void stop();
};

#endif
