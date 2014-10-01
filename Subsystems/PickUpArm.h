#ifndef PICK_UP_ARM_H
#define PICK_UP_ARM_H

#include "../Custom/DebuggingSubsystem.h"

class Victor;
class DigitalInput; 

class PickUpArm: public Subsystem {
public:
	PickUpArm();
	virtual ~PickUpArm();

	void setWheelSpeed(const float speed);
	bool hasBall(); 

protected:
	Victor* pickupWheelsMotor;
	DigitalInput* ballSensor; 
};

#endif
