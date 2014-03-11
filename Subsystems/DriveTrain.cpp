#include "DriveTrain.h"

#include "../RobotMap.h"
#include "../PIDMap.h"

#include "../Custom/SelfCleaningDrive.h"
#include "Talon.h"
#include <Gyro.h>
#include "Encoder.h"

#include "../Commands/ArcadeDriveCommand.h"

#include <iostream>

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
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

	gyro = new Gyro(GYRO_MODULE, GYRO_PORT);

	leftEncoder = new Encoder(
		ENCODER_MODULE,
		LEFT_ENCODER_A_PORT,
		ENCODER_MODULE,
		LEFT_ENCODER_B_PORT
	);
	rightEncoder = new Encoder(
		ENCODER_MODULE,
		RIGHT_ENCODER_A_PORT,
		ENCODER_MODULE,
		RIGHT_ENCODER_B_PORT

	);
	leftEncoder->SetDistancePerPulse(.053333333);
	rightEncoder->SetDistancePerPulse(.053333333);
	leftEncoder->Start();
	rightEncoder->Start();
}

DriveTrain::~DriveTrain() {
	delete drive;
	delete gyro;
	delete leftEncoder;
	delete rightEncoder;
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDriveCommand());
}

float DriveTrain::limitAcceleration(float current, float next)
{
	if (next > current + ACCELERATION_FACTOR)
	{
		return (current + ACCELERATION_FACTOR);
	}
	else if (next < current - ACCELERATION_FACTOR)
	{
		return (current - ACCELERATION_FACTOR);
	}
	else
	{
		return next;
	}
}

void DriveTrain::move(float yValue, float rotateValue) {
	currentY = limitAcceleration(currentY, yValue);
	currentRotate = limitAcceleration(currentRotate, rotateValue);

	directDrive(currentY, currentRotate, true);

	/*if (ticks % 50 == 0)
	{
		std::cout << "right: " << rightEncoder->GetDistance() << ", left: " << leftEncoder->GetDistance() << "\n";
		std::cout << "gyro: " << gyro->GetAngle() << "\n";
	}
	ticks++;*/
}

void DriveTrain::preciseMove(float yValue, float rotateValue) {
	currentY = (yValue * yValue) * MAX_Y_PRECISE_SPEED;
	currentRotate = (rotateValue * rotateValue) * MAX_ROTATE_PRECISE_SPEED;

	if (yValue < 0)
	{
		currentY *= -1;
	}
	if (rotateValue < 0)
	{
		currentRotate *= -1;
	}

	directDrive(currentY, currentRotate);
}

void DriveTrain::directDrive(float yValue, float rotateValue, bool squareInputs)
{
	// For some reason, we need to invert rotateValue
	// We really ought to investigate why that is...
	drive->ArcadeDrive(-yValue, -rotateValue, squareInputs);
}

float DriveTrain::PID(float current, float target, float p, float i, float d){
	//this code needs to run in a loop
	//p, i, and d are our constants to be defined in PIDMap
	//if you don't want to use p, i, or d,  set their value to 0 in PIDMap

	//Proportional
	error = current-target;
	p_out = p * error;

	//Integral
	totalError += error;
	i_out = i * error;

	//Derivative
	deltaError = error - previousError;
	d_out = d * deltaError;

	output = p_out + i_out + d_out;

	if (output > 1){
		return 1;
	}else if(output < -1){
		return -1;
	}else{
		return output;
	}
}

void DriveTrain::resetPID(){
	totalError = 0;
	previousError = 0;
	leftEncoder->Reset();
	rightEncoder->Reset();
}

void DriveTrain::driveWithPID(float target){
	move(PID(leftEncoder->GetDistance(),
			target,
			DRIVE_P,
			DRIVE_I,
			DRIVE_D),
		 0);
}

void DriveTrain::turnWithPID(float angle){
	move(0,
		PID(gyro->GetAngle(),
			angle,
			TURN_P,
			TURN_I,
			TURN_D));
}
