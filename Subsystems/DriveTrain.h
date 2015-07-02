#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include <CANTalon.h>
#include <vector>

#include "../Custom/DebuggingSubsystem.h"

class Gyro;

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
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

	Gyro* m_gyro;
	std::vector<CANTalon*> m_motors;
	std::vector<float> m_speeds;

	SensorMoveDirection m_direction;

	void equalizeMotors();
	void setOutputs(float maxValue);

	void setMode(CANTalon::ControlMode mode);
};

#endif
