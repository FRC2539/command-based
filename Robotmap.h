#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// Controls Drive Base Configuration
//#define FRONT_RIGHT_DRIVE_MOTOR_PORT 1
//#define FRONT_LEFT_DRIVE_MOTOR_PORT 2
//#define BACK_RIGHT_DRIVE_MOTOR_PORT 3
//#define BACK_LEFT_DRIVE_MOTOR_PORT 4
#define RIGHT_DRIVE_MOTOR_PORT 1
#define LEFT_DRIVE_MOTOR_PORT 2

#define GYRO_MODULE 1
#define GYRO_PORT 1

#define ENCODER_MODULE 1
#define LEFT_ENCODER_A_PORT 1
#define LEFT_ENCODER_B_PORT 2
#define RIGHT_ENCODER_A_PORT 3
#define RIGHT_ENCODER_B_PORT 4

#define ACCELERATION_FACTOR 0.0485
#define MAX_Y_PRECISE_SPEED 0.45
#define MAX_ROTATE_PRECISE_SPEED 0.45


// Controller Configuration
// The currently available controller types are:
// * LogitechAttack3
// * LogitechCrossfire
// * LogitechDualShock
#define DRIVER_CONTROLLER_TYPE "LogitechDualShock"
#define DRIVE_CONTROLLER_PORT 1
#define DRIVE_Y_AXIS "LeftY" // front and back
#define DRIVE_X_AXIS null // strafing left and right
#define DRIVE_ROTATE_AXIS "RightX" // turning left and right
#define PICK_UP_AXIS "DPadY"
#define PRECISE_MOVEMENT_BUTTON "LeftJoystick"
#define FIRE_BUTTON "A"
#define DRAWBACK_BUTTON "B"
#define OPEN_BUTTON "RightBumper"
#define CLOSE_BUTTON "LeftBumper"


// Pickup
#define PICK_UP_MOTOR_PORT 3
#define PICK_UP_PISTON_OPEN_PORT 3
#define PICK_UP_PISTON_CLOSED_PORT 4

//Compressor
#define PRESSURE_SWITCH_PORT 5
#define COMPRESSOR_PORT 1

//Shooter
#define SHIFTING_GEAR_MOTOR_MODULE 1
#define SHIFTING_GEAR_MOTOR_PORT 4
//Firing Mechanism
#define SHIFTING_GEAR_FORWARD_PISTON_MODULE 1
#define SHIFTING_GEAR_FORWARD_PISTON_PORT 1
#define SHIFTING_GEAR_REVERSE_PISTON_MODULE 1
#define SHIFTING_GEAR_REVERSE_PISTON_PORT 2 


#endif
