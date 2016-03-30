// Define Controllers as map with the form: Class, Port #
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 0);
ADD_CONTROLLER(LogitechDualShockController, 1);

/*
 * Driver Controller
 */

// Define Axes in the form: Controller Port #, Axis Name, Logical Axis
ADD_AXIS(0, LeftY, logicalAxes::DriveY);
ADD_AXIS(0, LeftX, logicalAxes::DriveX);
ADD_AXIS(0, RightX, logicalAxes::DriveRotate);

// Button commands can be added three ways:
// ADD_SIMPLE_BUTTON(Port #, Button Name, Command Name)
// ADD_TOGGLE_BUTTON(Port #, Button Name, Command Name)
// ADD_BUTTON(Port #, Button Name, Action, Command*)
//   Actions: WhenPressed, WhileHeld, WhenReleased, CancelWhenPressed, ToggleWhenPressed
ADD_SIMPLE_BUTTON(0, Back, ResetCommand);
ADD_BUTTON(0, DPadUp, WhenPressed, new DriveCommand(Config::DriveTrain::preciseModeMaxSpeed));
ADD_BUTTON(0, DPadDown, CancelWhenPressed, lastCommand);


/*
 * Backup Controller
 */

//ADD_SIMPLE_BUTTON(1, All, SelfDestructCommand);
ADD_BUTTON(1, LeftTrigger, WhenPressed, new SetShooterHeightCommand(Config::Shooter::minHeight));
ADD_BUTTON(1, LeftBumper, WhenPressed, new SetShooterHeightCommand(Config::Shooter::maxHeight));
ADD_SIMPLE_BUTTON(1, X, PickupCommand);
ADD_SIMPLE_BUTTON(1, A, FireCommand);
ADD_SIMPLE_BUTTON(1, B, LowGoalCommand);
ADD_BUTTON(1, RightTrigger, WhileHeld, new ShooterMoveCommand(Shooter::DOWN));
ADD_BUTTON(1, RightBumper, WhileHeld, new ShooterMoveCommand(Shooter::UP));
ADD_BUTTON(1, Y, WhileHeld, new ManualShooterCommand(.6));
