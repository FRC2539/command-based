#ifndef PICK_UP_ARM_H
#define PICK_UP_ARM_H

#include "../Custom/DebuggingSubsystem.h"
#include <DoubleSolenoid.h>

class Victor;
class DigitalInput; 

class PickUpArm: public Subsystem {
public:
	PickUpArm();
	virtual ~PickUpArm();

	void setWheelSpeed(const float speed);
	void setArmPosition(DoubleSolenoid::Value position);
	bool hasBall(); 
	DoubleSolenoid::Value getArmPosition();

protected:
	Victor* pickupWheelsMotor;
	DigitalInput* ballSensor; 
	DoubleSolenoid* armPiston;
	
	DoubleSolenoid::Value armPosition;
};

#endif
