#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// Controls Drive Base Configuration
#define DRIVE_MOTOR_CONTROLLER Talon
#define FRONT_RIGHT_DRIVE_MOTOR_PORT 1
#define FRONT_LEFT_DRIVE_MOTOR_PORT 2
#define BACK_RIGHT_DRIVE_MOTOR_PORT 3
#define BACK_LEFT_DRIVE_MOTOR_PORT 4

#define CONTROLLER_PORT 1
#define MOVE_AXIS 1 // front and back
#define TURN_AXIS 2 // left and right


#endif
