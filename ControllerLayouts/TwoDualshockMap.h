#ifndef CONTROLLER_MAP_H
#define CONTROLLER_MAP_H

// Define Controllers as map with the form: Port #, Type
// The currently available controller types are:
// * LogitechAttack3
// * LogitechCrossfire
// * LogitechDualShock
#define CONTROLLERS {{1, "LogitechDualShock"}, {2, "LogitechDualShock"}}

// Define Axes and Buttons in the form: Port #, Name

#define DRIVE_Y_AXIS 1, "LeftY" // front and back
#define DRIVE_X_AXIS null // strafing left and right
#define DRIVE_ROTATE_AXIS 1, "RightX" // turning left and right

#define PRECISE_MOVEMENT_BUTTON 1, "Start"

#define PICK_UP_BUTTON 2, "RightBumper"

#define FIRE_BUTTON 2, "A"
#define DRAWBACK_BUTTON 2, "B"

#define WHEEL_IN_BUTTON 2, "Y"
#define WHEEL_OUT_BUTTON 2, "X"

#define RESET_BUTTON 1, "Back"

#endif
