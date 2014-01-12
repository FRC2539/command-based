#include "DriveTrain.h"
#include "../Commands/ArcadeDriveCommand.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	frontRight = new DRIVE_MOTOR_CONTROLLER(FRONT_RIGHT_DRIVE_MOTOR_PORT);
	frontLeft = new DRIVE_MOTOR_CONTROLLER(FRONT_LEFT_DRIVE_MOTOR_PORT);
	backRight = new DRIVE_MOTOR_CONTROLLER(BACK_RIGHT_DRIVE_MOTOR_PORT);
	backLeft = new DRIVE_MOTOR_CONTROLLER(BACK_LEFT_DRIVE_MOTOR_PORT);

	drive = new RobotDrive(frontLeft, backLeft, frontRight, backRight);
	drive->SetSafetyEnabled(false);
}

DriveTrain::~DriveTrain() {
	delete frontRight;
	delete frontLeft;
	delete backRight;
	delete backLeft;

	delete drive;
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDriveCommand());
}

void DriveTrain::driveWithController(Joystick* controller) {
	drive->ArcadeDrive(controller, MOVE_AXIS, controller, TURN_AXIS);
}
