#ifndef PICK_UP_H
#define PICK_UP_H

#include "Commands/Subsystem.h"
#include <Victor.h>
#include <DoubleSolenoid.h>
#include "../Custom/AnalogUltrasonic.h"


class PickUp: public Subsystem {
public:
	PickUp();
	virtual ~PickUp();
	void InitDefaultCommand();

	void pickup(float direction);

	void open();
	void close();

	void distancePickup(float direction);

protected:
	Victor* motor;
	DoubleSolenoid* solenoid;
	AnalogUltrasonic* ultrasonic;
	bool canGoUp;
};

#endif
