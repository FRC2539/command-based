#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../Custom/DebuggingSubsystem.h"

class CANTalon;
class RatePIDController;

class Elevator: public Subsystem {
public:
	Elevator();
	virtual ~Elevator();

	virtual void InitDefaultCommand();

	void maintainHeight();
	void moveToward(int height);
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
	RatePIDController* pidLoop;

	unsigned int targetPosition;
	unsigned int level;
	bool fuzzyLevel;

	bool settingsLoaded;
};

#endif
