#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include <Victor.h>
#include <DoubleSolenoid.h>
#include <Relay.h>
#include <DigitalInput.h>

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
