#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../Custom/DebuggingSubsystem.h"

class CANTalon; 

class Elevator: public Subsystem {
public:
	Elevator();
	virtual ~Elevator();

	void changeLevel(int difference);
	bool onTarget();

	void directDrive(float speed);
	void recalculateLevel();

	void storeSettings();
	void loadSettings();

	void zeroElevator();

	void enableSoftLimits();
	void disableSoftLimits();

protected:
	int convertToLevel(int encoderValue);

	CANTalon* elevatorMotor;

	unsigned int targetPosition;
	unsigned int level;
	bool fuzzyLevel;

	bool settingsLoaded;
};

#endif
