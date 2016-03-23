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
ADD_BUTTON(0, DPadUp, WhenPressed, new DriveCommand(Config::DriveTrain::preciseModeMaxSpeed));
ADD_BUTTON(0, DPadDown, WhenPressed, new DriveCommand(Config::DriveTrain::maxSpeed));
/*
 * Other Controller
 */
/*
ADD_SIMPLE_BUTTON(1, All, SelfDestructCommand);
ADD_SIMPLE_BUTTON(1, LeftTrigger, SetShooterHeightDownCommandGroup);
ADD_SIMPLE_BUTTON(1, LeftBumper, SetShooterHeightUpCommandGroup);
ADD_SIMPLE_BUTTON(1, X, PickupCommandGroup);
ADD_SIMPLE_BUTTON(1, Start, LaunchBoulderCommand);
ADD_SIMPLE_BUTTON(1, A, FireCommand);
ADD_SIMPLE_BUTTON(1, B, LowGoalCommand);
ADD_BUTTON(1, RightTrigger, WhileHeld, IncrementShooterDownCommand);
ADD_BUTTON(1, RightBumper, WhileHeld, IncrementShooterUpCommand);
*/

