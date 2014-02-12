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
	void off();
	void releaseLauncher();
	void holdLauncher();
	void retractLauncher();
	bool down();
protected:
	Victor* motor;
	DoubleSolenoid* piston;
	Relay* electromagnet;
	DigitalInput* downSwitch;
};

#endif
