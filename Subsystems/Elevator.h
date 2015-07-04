#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../Custom/DebuggingSubsystem.h"

class CANTalon;

class Elevator: public Subsystem {
public:
	Elevator();
	virtual ~Elevator();

	virtual void InitDefaultCommand();

	enum Direction {
		UP,
		DOWN,
		HOLD
	};

	void go(Direction direction);
	void goTo(int height);
	void changeLevel(int difference);

	bool atTargetPosition();
	void updateDashboardHeight();

protected:
	void calculateLevel();

	void storeSettings();
	void loadSettings();

	void updateDashboardLevel();

	CANTalon* m_elevatorMotor;

	int m_targetHeight;
	bool m_atExactLevel;
	Direction m_direction;

	int m_currentLevel;
	int m_maxLevel;

	bool m_settingsLoaded;
};

#endif
