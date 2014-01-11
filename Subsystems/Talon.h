#ifndef TALON_SYSTEM_H
#define TALON_SYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class TalonSystem: public Subsystem {
protected:
	Talon motor;

public:
	TalonSystem();
	void InitDefaultCommand();

	void run(float speed);
	void stop();
};

#endif
