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
ADD_TOGGLE_BUTTON(0, LeftJoystick, new DriveCommand(Config::DriveTrain::preciseModeMaxSpeed));
ADD_TOGGLE_BUTTON(0, RightJoystick, new FixedHeadingCommand());
ADD_BUTTON(0, DPadUp, WhenPressed, new AlignmentTurnCommand(0));
ADD_BUTTON(0, DPadRight, WhenPressed, new AlignmentTurnCommand(90));
ADD_BUTTON(0, DPadLeft, WhenPressed, new AlignmentTurnCommand(270));
ADD_BUTTON(0, DPadDown, WhenPressed, new AlignmentTurnCommand(180));
ADD_SIMPLE_BUTTON(0, Y, GyroCrossDefenseCommand);
/*
 * Other Controller
 */

ADD_BUTTON(1, RightTrigger, WhenPressed, new SetShooterHeightDownCommandGroup());
ADD_BUTTON(1, RightBumper, WhenPressed, new SetShooterHeightUpCommandGroup());
//ADD_BUTTON(1, LeftBumper, WhenPressed, new SetPickupArmsHeightCommand(Config::PickupArms::maxHeight));
//ADD_BUTTON(1, LeftTrigger, WhenPressed, new SetPickupArmsHeightCommand(Config::PickupArms::minHeight));
ADD_BUTTON(1, Start, WhenPressed, new LaunchBoulderCommand());
ADD_BUTTON(1, X, WhenPressed, new CollectBoulderCommand());
//ADD_BUTTON(1, X, WhenPressed, new PickupCommand());
//ADD_BUTTON(1, A, WhenPressed, new LowGoalCommand());
ADD_BUTTON(1, Y, WhenPressed, new StopPickupCommand());
ADD_BUTTON(1, A, WhenPressed, new LaunchBoulderCommand());
