#include "DriveTrain.h"
#include "../Commands/ArcadeDriveCommand.h"
#include "../Custom/SelfCleaningDrive.h"
#include "Talon.h"
#include "../Robotmap.h"
#include <iostream>
#include <cmath>

DriveTrain::DriveTrain() :
	Subsystem("DriveTrain"),
	currentY(0),
	currentRotate(0)
	{

    #ifdef FRONT_RIGHT_DRIVE_MOTOR_PORT
	drive = new SelfCleaningDrive(
        new Talon(FRONT_LEFT_DRIVE_MOTOR_PORT),
        new Talon(BACK_LEFT_DRIVE_MOTOR_PORT),
        new Talon(FRONT_RIGHT_DRIVE_MOTOR_PORT),
        new Talon(BACK_RIGHT_DRIVE_MOTOR_PORT)
    );
    #endif
    #ifdef RIGHT_DRIVE_MOTOR_PORT
    drive = new SelfCleaningDrive(
        new Talon(LEFT_DRIVE_MOTOR_PORT),
        new Talon(RIGHT_DRIVE_MOTOR_PORT)
    );
    #endif

    drive->SetSafetyEnabled(false);
}

DriveTrain::~DriveTrain() {
	delete drive;
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDriveCommand());
}

void DriveTrain::move(float yValue, float rotateValue) {
	if (yValue > currentY + ACCELERATION_FACTOR)
	{
		currentY += ACCELERATION_FACTOR;
	}
	else if (yValue < currentY - ACCELERATION_FACTOR)
	{
		currentY -= ACCELERATION_FACTOR;
	}

	if (rotateValue > currentRotate + ACCELERATION_FACTOR)
	{
		currentRotate += ACCELERATION_FACTOR;
	}
	else if (rotateValue < currentRotate - ACCELERATION_FACTOR)
	{
		currentRotate -= ACCELERATION_FACTOR;
	}

	// For some reason, we need to invert rotateValue
	// We really ought to investigate why that is...
	drive->ArcadeDrive(currentY, -currentRotate, true);
}
