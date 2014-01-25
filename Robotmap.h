
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


// Controller Configuration
// The currently available controller types are:
// * LogitechAttack3
// * LogitechCrossfire
// * LogitechDualShock
#define DRIVER_CONTROLLER_TYPE "LogitechAttack3"
#define DRIVE_CONTROLLER_PORT 1
#define DRIVE_Y_AXIS kYAxis // front and back
#define DRIVE_X_AXIS null // strafing left and right
#define DRIVE_ROTATE_AXIS kXAxis // turning left and right


