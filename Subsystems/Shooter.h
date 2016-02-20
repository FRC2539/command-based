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

	void calculateTargetPosition();
	Target getTarget();

	void pivotToHeight(double position);
	void setPickerUpperRotateSpeed(float speed);
	void setShooterSpeed(float speed);
	bool hasBall();

protected:
	DigitalInput m_ballDetector;

	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_indexWheel;
	CANTalon m_shooterWheel;

	std::shared_ptr<NetworkTable> m_gripOutput;
	std::shared_ptr<NetworkTable> m_targetInfo;
	int m_cameraWidth;
};