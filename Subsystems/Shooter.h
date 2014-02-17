#ifndef SHOOTER_H
#define SHOOTER_H

#include "Commands/Subsystem.h"

class Victor;
class DoubleSolenoid;
class Relay;
class DigitalInput;

class Shooter: public Subsystem {
public:
	Shooter();
	virtual ~Shooter();

	void InitDefaultCommand();

	void releaseLauncher();
	void retractLauncher();
	void runBack();
	void stopMotor();
	void off();
	void reset();

	bool down();
protected:
	Victor* motor;
	DoubleSolenoid* piston;
	Relay* electromagnet;
	DigitalInput* downSwitch;
};

#endif
