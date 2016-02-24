// Define Controllers as map with the form: Class, Port #
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 0);

// Define Axes in the form: Controller Port #, Axis Name, Logical Axis
ADD_AXIS(0, LeftY, logicalAxes::DriveY);
ADD_AXIS(0, LeftX, logicalAxes::DriveX);
ADD_AXIS(0, RightX, logicalAxes::DriveRotate);

// Button Commands: Controller Port #, Button Name, Action, Command
// For TOGGLE and SIMPLE, the Action should be omitted
ADD_TOGGLE_BUTTON(0, LeftJoystick, new DriveCommand(Config::DriveTrain::preciseModeMaxSpeed));
ADD_SIMPLE_BUTTON(0, Back, ResetCommand);
ADD_TOGGLE_BUTTON(0, RightJoystick, new FixedHeadingCommand());
ADD_BUTTON(0, DPadUp, WhenPressed, new AlignmentTurnCommand(0));
ADD_BUTTON(0, DPadRight, WhenPressed, new AlignmentTurnCommand(90));
ADD_BUTTON(0, DPadLeft, WhenPressed, new AlignmentTurnCommand(270));
ADD_BUTTON(0, DPadDown, WhenPressed, new AlignmentTurnCommand(180));
ADD_BUTTON(0, X, WhileHeld, new MotorTestCommand(1));
ADD_SIMPLE_BUTTON(0, Y, GyroCrossDefenseCommand);
ADD_SIMPLE_BUTTON(0, Start, MoveToPosition);
