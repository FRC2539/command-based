#include "MecanumDriveTrain.h"

#include "../RobotMap.h"

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <Talon.h>
#include <Gyro.h>
#include <Encoder.h>

#include "../Commands/ArcadeDriveCommand.h"

MecanumDriveTrain::MecanumDriveTrain() : Subsystem("MecanumDriveTrain"),
	currentY(0),
	currentRotate(0)
{
	frontRightMotor = new Talon(RobotMap::DriveBase::frontLeftMotorsPort);
	frontLeftMotor = new Talon(RobotMap::DriveBase::frontRightMotorsPort);
	backRightMotor = new Talon(RobotMap::DriveBase::backLeftMotorsPort);
	backLeftMotor = new Talon(RobotMap::DriveBase::backRightMotorsPort);

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

	drive = new EncoderDrive(frontLeftMotor, frontRightMotor, backLeftMotor, backRightMotor);
	drive->SetSafetyEnabled(false);

	DEBUG_SENSOR(leftEncoder);
	DEBUG_SENSOR(rightEncoder);

	DEBUG_MOTOR(frontleftMotor);
	DEBUG_MOTOR(frontrightMotor);
	DEBUG_MOTOR(backleftMotor);
	DEBUG_MOTOR(backrightMotor);
}

MecanumDriveTrain::~MecanumDriveTrain() {
	delete drive;
	delete frontLeftMotor;
	delete frontRightMotor;
	delete backLeftMotor;
	delete backRightMotor;
	delete leftEncoder;
	delete rightEncoder;
}

void MecanumDriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDriveCommand());
}

void MecanumDriveTrain::move(float yValue, float xValue, float rotate) {
	drive->MecanumDrive_Cartesian(-xValue, -yValue, -rotate);
}

void MecanumDriveTrain::setMaxSpeed(float speed)
{
	drive->setMaxSpeed(speed);
}

