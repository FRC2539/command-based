#ifndef PICK_UP_H
#define PICK_UP_H

#include "Commands/Subsystem.h"

class Victor;
class DoubleSolenoid;
class DigitalInput;
class AnalogUltrasonic;

class PickUp: public Subsystem {
public:
	PickUp();
	virtual ~PickUp();
	void InitDefaultCommand();

	void pickup(float direction);

	bool seesBall();
	bool isDown();

	void open();
	void close();

protected:
	Victor* motor;
	DoubleSolenoid* solenoid;
	AnalogUltrasonic* ultrasonic;
	DigitalInput* downLimitSwitch;

};

#endif
