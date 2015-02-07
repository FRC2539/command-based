#include "MecanumDriveTrain.h"

#include "../RobotMap.h"
#if defined(MECANUM_DRIVE)

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <CANTalon.h>
#include <Gyro.h>

#include "../Custom/Netconsole.h"

MecanumDriveTrain::MecanumDriveTrain() : DriveTrain("MecanumDriveTrain")
{
	frontRightMotor = new CANTalon(RobotMap::DriveBase::frontRightMotorID);
	frontLeftMotor = new CANTalon(RobotMap::DriveBase::frontLeftMotorID);
	backRightMotor = new CANTalon(RobotMap::DriveBase::backRightMotorID);
	backLeftMotor = new CANTalon(RobotMap::DriveBase::backLeftMotorID);
	
	gyro = new Gyro(RobotMap::DriveBase::gyroPort);
	gyro->SetSensitivity(RobotMap::DriveBase::gyroSensitivity);
	enableGyro = false;

	drive = new EncoderDrive(frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
	drive->SetSafetyEnabled(false);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

	DEBUG_MOTOR(frontLeftMotor);
	DEBUG_MOTOR(frontRightMotor);
	DEBUG_MOTOR(backLeftMotor);
	DEBUG_MOTOR(backRightMotor);

	DEBUG_SENSOR(gyro);
}

MecanumDriveTrain::~MecanumDriveTrain()
{
	delete frontLeftMotor;
	delete frontRightMotor;
	delete backLeftMotor;
	delete backRightMotor;

	delete gyro;
}

void MecanumDriveTrain::move(float xValue, float yValue, float rotate)
{
	drive->MecanumDrive(xValue, yValue, rotate, GyroAngle());
}

void MecanumDriveTrain::stop()
{
	drive->MecanumDrive(0.0, 0.0, 0.0);
	gyro->Reset();
	drive->resetEncoders();
}

void MecanumDriveTrain::useGyro(bool isActive)
{
	enableGyro = isActive;
}

float MecanumDriveTrain::GyroAngle()
{
	if (enableGyro)
	{
		return gyro->GetAngle();
	}

	return 0;
}

#endif
