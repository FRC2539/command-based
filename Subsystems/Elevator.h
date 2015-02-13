#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../Custom/DebuggingSubsystem.h"

class CANTalon; 

class Elevator: public Subsystem {
public:
	Elevator();
	virtual ~Elevator();
	virtual void InitDefaultCommand();

	void changePosition(int difference);

protected:
	CANTalon* elevatorMotor;
};

#endif
