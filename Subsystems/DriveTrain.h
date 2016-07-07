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
	std::vector<double> getEncoderSpeeds();
	std::vector<double> getEncoderPositions();

	void useEncoders();
	void ignoreEncoders();
	 
	enum class DefenseState {
		Up,
		Down, 
		Floor,
		Defense
	};

	enum SensorMoveDirection {
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
	void setEncoderTargetPositions(std::vector<float> positions);
	bool atTargetPosition();

protected:
	float m_maxSpeed;
	float m_maxPercentVBus;
	bool m_readEncoders;
	double m_last[3];

	bool m_fieldOrientation;
	double m_gyroOffset;

	std::vector<std::shared_ptr<CANTalon>> m_allMotors;
	std::vector<std::shared_ptr<CANTalon>> m_activeMotors;
	
	DefenseState m_defenseLastState;
	std::vector<float> m_speeds;
	bool m_wasStopped;
	AHRS m_navX;

	void setOutputs();

	void setMode(CANTalon::ControlMode mode);
};
