#pragma once

#include <CANTalon.h>
#include <DigitalInput.h>
#include <memory>

class NetworkTable;

#include "../Custom/DebuggingSubsystem.h"

class Shooter: public Subsystem {
public:
	Shooter();

	struct Target
	{
		bool found = false;
		double distance = 0;
		double position = 0;
	};

	Target getTarget();

	void setIndexerSpeed(double speed);
	void setShooterSpeed(double speed);
	void manualShooter(double power);
	void stopShooter();
	bool readyToFire();
	bool hasBall();
	void manualPivot(double power);

	int getHeight();
	void setEncoderPosition(int position=0);
	void storeEncoderPosition();
	bool atTopLimit();
	bool atBottomLimit();

	enum Direction {
		UP,
		DOWN
	};

	void holdAt(int position);
	void move(Direction direction);

protected:
	DigitalInput m_ballDetector;

	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_indexWheel;
	CANTalon m_shooterWheel;

	std::shared_ptr<NetworkTable> m_targetInfo;

	Direction m_direction;
	bool atKnownPosition();
	bool m_settingsLoaded;
};