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

	void pivotToHeight(int position);
	void setIndexerSpeed(float speed);
	void setShooterSpeed(float speed);
	void stopShooter();
	bool readyToFire();
	bool hasBall();
	void manualRun(float power);
	int getHeight();
	void setEncoderPosition(int position=0);
	void storeEncoderPosition();

protected:
	DigitalInput m_ballDetector;

	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_indexWheel;
	CANTalon m_shooterWheel;

	std::shared_ptr<NetworkTable> m_targetInfo;

	bool atKnownPosition();
	bool m_settingsLoaded;
};