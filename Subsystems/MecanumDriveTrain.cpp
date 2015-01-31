#include "MecanumDriveTrain.h"

#include "../RobotMap.h"
#if defined(MECANUM_DRIVE)

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <CANTalon.h>
#include <Gyro.h>

MecanumDriveTrain::MecanumDriveTrain() : DriveTrain("MecanumDriveTrain")
{
	frontRightMotor = new CANTalon(RobotMap::DriveBase::frontLeftMotorID);
	frontLeftMotor = new CANTalon(RobotMap::DriveBase::frontRightMotorID);
	backRightMotor = new CANTalon(RobotMap::DriveBase::backLeftMotorID);
	backLeftMotor = new CANTalon(RobotMap::DriveBase::backRightMotorID);

	gyro = new Gyro(RobotMap::DriveBase::gyroPort);
	gyro->SetSensitivity(RobotMap::DriveBase::gyroSensitivity);

	drive = new EncoderDrive(frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor);
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

	delete gyro;
}

void MecanumDriveTrain::move(float xValue, float yValue, float rotate)
{
	drive->MecanumDrive(xValue, yValue, rotate, gyro->GetAngle());
}

void MecanumDriveTrain::stop()
{
	drive->MecanumDrive(0.0, 0.0, 0.0);
}

#endif
