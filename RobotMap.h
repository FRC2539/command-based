#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// Controls Drive Base Configuration
//#define FRONT_LEFT_DRIVE_MOTOR_PORT 2
//#define FRONT_RIGHT_DRIVE_MOTOR_PORT 1
//#define BACK_LEFT_DRIVE_MOTOR_PORT 4
//#define BACK_RIGHT_DRIVE_MOTOR_PORT 3
#define LEFT_DRIVE_MOTOR_PORT 2
#define RIGHT_DRIVE_MOTOR_PORT 1

#define GYRO_MODULE 1
#define GYRO_PORT 1

#define ENCODER_MODULE 1
#define LEFT_ENCODER_A_PORT 1
#define LEFT_ENCODER_B_PORT 2
#define RIGHT_ENCODER_A_PORT 3
#define RIGHT_ENCODER_B_PORT 4

#define ACCELERATION_FACTOR 0.0485
#define PRECISE_MODE_MAX_Y 0.45
#define PRECISE_MODE_MAX_ROTATE 0.45

//Compressor
#define COMPRESSOR_PORT 1
#define PRESSURE_SWITCH_PORT 5

#endif
