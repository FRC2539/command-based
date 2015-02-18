#include "MecanumDriveTrain.h"

#include "../RobotMap.h"
#if defined(MECANUM_DRIVE)

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <CANTalon.h>
#include <Gyro.h>

#include "../Custom/Netconsole.h"

MecanumDriveTrain::MecanumDriveTrain() :
	DriveTrain("MecanumDriveTrain"),
	PIDSource(),
	PIDOutput(),
	enableGyro(false),
	currentMode(DriveY)
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
	resetGyro();
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

void MecanumDriveTrain::resetGyro()
{
	gyro->Reset();
}

double MecanumDriveTrain::PIDGet()
{
	if (currentMode == DriveX)
	{
		float position = frontLeftMotor->GetPosition();
		position += frontRightMotor->GetPosition(); // double inverted
		position += backLeftMotor->GetPosition() * -1;
		position += backRightMotor->GetPosition() * -1;

		return position / 4;
	}
	else if (currentMode == DriveY)
	{
		float position = frontLeftMotor->GetPosition();
		position += frontRightMotor->GetPosition() * -1;
		position += backLeftMotor->GetPosition();
		position += backRightMotor->GetPosition() * -1;
	
		return position / 4;
	}

	return gyro->GetAngle();
}

void MecanumDriveTrain::PIDWrite(float output)
{
	if (currentMode == DriveX)
	{
		move(output, 0, 0);
	}
	else if (currentMode == DriveY)
	{
		move(0, output, 0);
	}
	else
	{
		move(0, 0, output);
	}
}

void MecanumDriveTrain::setPIDMode(PIDMode mode)
{
	currentMode = mode;
}

#endif
