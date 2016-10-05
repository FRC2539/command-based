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
	bool doneShooting();
	void setDoneShooting(bool done);
	bool readyToFire();
	bool hasBall();

	int getHeight();
	bool atTopLimit();
	bool atBottomLimit();
	
	void zeroPivotEncoder();

	void holdAt(int position);
	void pivot(int speed);
	void manualPivot(double power);

protected:
	DigitalInput m_ballDetector;
	bool m_doneShooting;

	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_indexWheel;
	CANTalon m_shooterWheel;

	std::shared_ptr<NetworkTable> m_targetInfo;
};
