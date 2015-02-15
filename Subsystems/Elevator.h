#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../Custom/DebuggingSubsystem.h"

class CANTalon; 

class Elevator: public Subsystem {
public:
	Elevator();
	virtual ~Elevator();

	void changePosition(int difference);
	bool onTarget();
	void directDrive(float percentVoltage);
	void endDirectDrive();
	int GetPosition();
	void SetPosition(int ElevatorPosition);

protected:
	CANTalon* elevatorMotor;

	unsigned int targetPosition;
	unsigned int minPosition;
	unsigned int maxPosition;
};

#endif
