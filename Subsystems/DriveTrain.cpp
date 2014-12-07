#include "DriveTrain.h"

#include "../RobotMap.h"

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <Talon.h>
#include <Gyro.h>
#include <Encoder.h>

#include "../Commands/ArcadeDriveCommand.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	currentY(0),
	currentRotate(0)
{
	rightMotor = new Talon(RobotMap::DriveBase::leftMotorsPort);
	leftMotor = new Talon(RobotMap::DriveBase::rightMotorsPort);

	leftEncoder = new Encoder(
		RobotMap::DriveBase::leftEncoderPortA,
		RobotMap::DriveBase::leftEncoderPortB
	);
	rightEncoder = new Encoder(
		RobotMap::DriveBase::rightEncoderPortA,
		RobotMap::DriveBase::rightEncoderPortB
	);
	leftEncoder->SetDistancePerPulse(RobotMap::DriveBase::encoderSensitivity);
	rightEncoder->SetDistancePerPulse(RobotMap::DriveBase::encoderSensitivity);
	leftEncoder->Reset();
	leftEncoder->Start();
	rightEncoder->Reset();
	rightEncoder->Start();
	
	drive = new RobotDrive(leftMotor, rightMotor);

	//drive = new EncoderDrive(leftMotor, rightMotor, leftEncoder, rightEncoder);
	drive->SetSafetyEnabled(false);
	//drive->ignoreEncoders();

	gyro = new Gyro(RobotMap::DriveBase::gyroPort);
	gyro->Reset();
	gyro->SetSensitivity(RobotMap::DriveBase::gyroSensitivity);

	DEBUG_SENSOR(gyro);
	DEBUG_SENSOR(leftEncoder);
	DEBUG_SENSOR(rightEncoder);

	DEBUG_MOTOR(leftMotor);
	DEBUG_MOTOR(rightMotor);
}

DriveTrain::~DriveTrain() {
	delete drive;
	delete leftMotor;
	delete rightMotor;
	delete gyro;
	delete leftEncoder;
	delete rightEncoder;
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDriveCommand());
}

float DriveTrain::limitAcceleration(float current, float next)
{
	if (next > current + RobotMap::DriveBase::accelerationFactor)
	{
		return (current + RobotMap::DriveBase::accelerationFactor);
	}
	else if (next < current - RobotMap::DriveBase::accelerationFactor)
	{
		return (current - RobotMap::DriveBase::accelerationFactor);
	}
	else
	{
		return next;
	}
}

void DriveTrain::move(float yValue, float rotate) {
	currentY = limitAcceleration(currentY, yValue);
	currentRotate = limitAcceleration(currentRotate, rotate);

	directDrive(currentY, currentRotate, true);
}

void DriveTrain::directDrive(float yValue, float rotateValue, bool squareInputs)
{
	drive->ArcadeDrive(-yValue, -rotateValue, squareInputs);
}

