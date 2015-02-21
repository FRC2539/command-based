#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../Custom/DebuggingSubsystem.h"

class CANTalon;

class Elevator: public Subsystem {
public:
	Elevator();
	virtual ~Elevator();

	virtual void InitDefaultCommand();

	void maintainHeight();
	void moveToward(unsigned int height);
	void changeLevel(int difference);
	bool onTarget();

	void directDrive(float speed);
	void recalculateLevel();

	void storeSettings();
	void loadSettings();

	void zeroElevator();

	void displayLevel();
	void displayHeight();

	void enableSoftLimits();
	void disableSoftLimits();

	enum Direction {
		UP,
		DOWN,
		HOLD
	};

protected:
	CANTalon* elevatorMotor;

	unsigned int targetPosition;
	bool atExactLevel;
	Direction direction;

	int level;
	int maxLevel;

	bool settingsLoaded;
};

#endif
