#include "DriveTrain.h"
#include "../Commands/ArcadeDriveCommand.h"
#include "../Custom/SelfCleaningDrive.h"
#include "Talon.h"
#include "../Robotmap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

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
	drive->ArcadeDrive(yValue, rotateValue);
}
