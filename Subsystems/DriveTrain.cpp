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
	leftEncoder->Start();
	rightEncoder->Start();

	drive = new EncoderDrive(leftMotor, rightMotor, leftEncoder, rightEncoder);
	drive->SetSafetyEnabled(false);

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

void DriveTrain::move(float yValue, float rotate) {
	drive->ArcadeDrive(-yValue, -rotate, true);
}

void DriveTrain::setMaxSpeed(float speed)
{
	drive->setMaxSpeed(speed);
}


