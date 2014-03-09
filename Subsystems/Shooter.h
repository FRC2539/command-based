#ifndef SHOOTER_H
#define SHOOTER_H

#include "Commands/Subsystem.h"

class Victor;
class Relay;
class DigitalInput;

class Shooter: public Subsystem {
public:
	Shooter();
	virtual ~Shooter();

	void releaseLauncher();
	void retractLauncher();
	void runBack();
	void reset();

	bool down();

protected:
	Victor* motor;
	Relay* electromagnet;
	DigitalInput* downSwitch;
};

#endif
