#ifndef PICK_UP_H
#define PICK_UP_H


#include "Commands/Subsystem.h"

class Victor;
class DoubleSolenoid;


class PickUp: public Subsystem {
public:
	PickUp();
	virtual ~PickUp();
	void InitDefaultCommand();

	void pickup(float direction);
	void raiseArm();
	void lowerArm();


protected:
	Victor* motor;
	DoubleSolenoid* piston;

private:
    int ticks;
};

#endif
