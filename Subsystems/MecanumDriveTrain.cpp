#include "MecanumDriveTrain.h"

#include "../RobotMap.h"
#if defined(MECANUM_DRIVE)

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <CANTalon.h>
#include <Gyro.h>

MecanumDriveTrain::MecanumDriveTrain() : DriveTrain("MecanumDriveTrain")
{
	frontRightMotor = new CANTalon(RobotMap::DriveBase::frontLeftMotorsPort);
	frontLeftMotor = new CANTalon(RobotMap::DriveBase::frontRightMotorsPort);
	backRightMotor = new CANTalon(RobotMap::DriveBase::backLeftMotorsPort);
	backLeftMotor = new CANTalon(RobotMap::DriveBase::backRightMotorsPort);

	drive = new EncoderDrive(frontLeftMotor, frontRightMotor, backLeftMotor, backRightMotor);
	drive->SetSafetyEnabled(false);

	DEBUG_MOTOR(frontleftMotor);
	DEBUG_MOTOR(frontrightMotor);
	DEBUG_MOTOR(backleftMotor);
	DEBUG_MOTOR(backrightMotor);
}

MecanumDriveTrain::~MecanumDriveTrain()
{
	delete frontLeftMotor;
	delete frontRightMotor;
	delete backLeftMotor;
	delete backRightMotor;
}

void MecanumDriveTrain::move(float xValue, float yValue, float rotate)
{
	drive->MecanumDrive_Cartesian(-xValue, -yValue, -rotate);
}

void MecanumDriveTrain::stop()
{
	drive->MecanumDrive_Cartesian(0.0, 0.0, 0.0);
}

#endif