// Define Controllers as map with the form: Class, Port #
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 0);
ADD_CONTROLLER(LogitechDualShockController, 1);

/*
 * Drive Controller
 */

// Define Axes in the form: Controller Port #, Axis Name, Logical Axis
ADD_AXIS(0, LeftY, logicalAxes::DriveY);
ADD_AXIS(0, LeftX, logicalAxes::DriveX);
ADD_AXIS(0, RightX, logicalAxes::DriveRotate);

ADD_SIMPLE_BUTTON(0, Back, ResetCommand);
ADD_TOGGLE_BUTTON(0, A, new DriveCommand(Config::DriveTrain::preciseModeMaxSpeed));

/*
 * Other Controller
 */

ADD_SIMPLE_BUTTON(1, Back, ResetCommand);

