#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include <Victor.h>
#include <DoubleSolenoid.h>

class Shooter: public Subsystem {
public:
	Shooter();
	virtual ~Shooter();
	void InitDefaultCommand();
	void off();
	void releaseLauncher();
	void retractLauncher();
protected:
	Victor* motor;
	DoubleSolenoid* piston;
};

#endif
