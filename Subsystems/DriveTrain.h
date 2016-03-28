#pragma once

#include <CANTalon.h>
#include <AHRS.h>
#include <vector>
#include <memory>

#include "../Custom/DebuggingSubsystem.h"

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual void InitDefaultCommand();

	void setMaxSpeed(float speed);
	void move(float x, float y, float rotate);
	void stop();

	void enableFieldOrientation(bool isActive=true);
	void disableFieldOrientation();

	float getAngle();
	void setGyroAngle(double angle);
	void resetGyro();

	double getAcceleration();

	void useEncoders();
	void ignoreEncoders();
	 
	enum class DefenseState {
		Up,
		Down, 
		Floor,
		Defense
	};

	enum class SensorMoveDirection {
		DriveX,
		DriveY,
		Rotate
	};

	void calculateDefenseState();
	DefenseState getDefenseState();
	
	void moveDistance(
		double distance,
		SensorMoveDirection direction=SensorMoveDirection::DriveY
	);
	bool doneMoving();

protected:
	float m_maxSpeed;
	bool m_readEncoders;

	bool m_fieldOrientation;
	double m_gyroOffset;

	std::vector<std::shared_ptr<CANTalon>> m_motors;
	
	DefenseState m_defenseLastState;
	std::vector<float> m_speeds;
	bool m_stopped;
	AHRS m_navX;

	void equalizeMotors();
	void handleStop();
	void setOutputs(float maxValue);

	void setMode(CANTalon::ControlMode mode, bool resetAll=false);
};
