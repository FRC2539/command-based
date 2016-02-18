#pragma once

#include <CANTalon.h>
#include <vector>
#include <memory>
#include <DigitalInput.h>

#include "../Custom/DebuggingSubsystem.h"


class Shooter: public Subsystem {
public:
	Shooter();

	void setMaxSpeed(float speed);
	void getTarget();
	void pivotToHeight(double position);
	void setPickerUpperRotateSpeed(float speed);
	void setShooterSpeed(float speed);
	bool hasBall();

protected:
	float m_maxSpeed;
	float m_maxTall;
	float m_minTall;
	DigitalInput m_maxTallLS;
	DigitalInput m_minTallLS;
	DigitalInput m_ballDetector;

	CANTalon m_tallMotorLeft;
	CANTalon m_tallMotorRight;
	CANTalon m_indexWheel;
	CANTalon m_shooterWheel;

private:
	int CameraWidth;
};