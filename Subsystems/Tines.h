#ifndef TINES_H
#define TINES_H

#include "../Custom/DebuggingSubsystem.h"

class Talon; 
class AnalogPotentiometer;
class Tines: public Subsystem {
public:
	Tines();
	virtual ~Tines();

	void directDrive(float percentVoltage);
	double getWidth();

protected:
	Talon* tinesMotor;
	AnalogPotentiometer* distanceDetector;
	unsigned int minPosition;
	unsigned int maxPosition;
};

#endif
