#pragma once

#include <CANTalon.h>
#include <AHRS.h>
#include <vector>
#include <memory>

#include "../Custom/DebuggingSubsystem.h"


class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain() = default;
	virtual void InitDefaultCommand();

	void setMaxSpeed(float speed);
	void move(float x, float y, float rotate);
	void stop();

	void enableFieldOrientation(bool isActive=true);
	void disableFieldOrientation();
	float getAngle();
	void resetGyro();

	void useEncoders();
	void ignoreEncoders();

	enum SensorMoveDirection {
		DriveX,
		DriveY,
		Rotate
	};

	void moveDistance(double distance, SensorMoveDirection direction=DriveY);
	bool doneMoving();

protected:
	float m_maxSpeed;
	bool m_fieldOrientation;
	bool m_readEncoders;

	std::unique_ptr<AnalogGyro> m_gyro;
	std::vector<std::unique_ptr<CANTalon>> m_motors;
	std::vector<float> m_speeds;
	AHRS m_navX;

	void equalizeMotors();
	void setOutputs(float maxValue);

	void setMode(CANTalon::ControlMode mode, bool resetAll=false);
};
