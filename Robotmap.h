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


// Pickup
#define PICK_UP_MOTOR_PORT 3
#define PICK_UP_PISTON_OPEN_PORT 1
#define PICK_UP_PISTON_CLOSED_PORT 2
#define PICK_UP_ULTRASONIC_PORT 2

//Compressor
#define PRESSURE_SWITCH_PORT 5
#define COMPRESSOR_PORT 1

//Shooter
#define SHIFTING_GEAR_MOTOR_PORT 4
//Firing Mechanism
#define SHIFTING_GEAR_FORWARD_PISTON_PORT 3
#define SHIFTING_GEAR_REVERSE_PISTON_PORT 4 
#define SHOOTER_ELECTROMAGNET_PORT 2
#define SHOOTER_DOWNSWITCH_PORT 6


#endif
