#ifndef MECANUM_DRIVE_TRAIN_H
#define MECANUM_DRIVE_TRAIN_H

#include "DriveTrain.h"
#include <PIDSource.h>
#include <PIDOutput.h>

class CANTalon;
class Gyro;

class MecanumDriveTrain: public DriveTrain, public PIDSource, public PIDOutput {
public:
	MecanumDriveTrain();
	virtual ~MecanumDriveTrain();

	void move(float xValue, float yValue, float rotateValue);
	virtual void stop();

	void useGyro(bool isActive);
	void resetGyro();

	enum PIDMode {
		DriveX,
		DriveY,
		Rotate
	};

	virtual double PIDGet();
	virtual void PIDWrite(float output);
	void setPIDMode(PIDMode mode);
	
	float currentSpeed();

protected:
	float GyroAngle();

	CANTalon* frontLeftMotor;
	CANTalon* frontRightMotor;
	CANTalon* backLeftMotor;
	CANTalon* backRightMotor;

	Gyro* gyro;

	bool enableGyro;
	PIDMode currentMode;
};

#define MOVE_WITH_JOYSTICK\
	move(\
		oi->getAxisValue(logicalAxes::DriveX),\
		oi->getAxisValue(logicalAxes::DriveY),\
		oi->getAxisValue(logicalAxes::DriveRotate)\
	)

#endif
