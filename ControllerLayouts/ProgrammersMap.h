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

//ADD_BUTTON(1, LeftJoystick, WhileHeld, new PreciseDriveCommand());
ADD_TOGGLE_BUTTON(0, LeftJoystick, PreciseDriveCommand);
ADD_SIMPLE_BUTTON(0, Back, ResetCommand);
ADD_BUTTON(0, RightBumper, WhileHeld, new ButtonElevatorCommand(RobotMap::Elevator::stepSpeed));
ADD_BUTTON(0, RightTrigger, WhileHeld, new ButtonElevatorCommand(-RobotMap::Elevator::stepSpeed));
ADD_SIMPLE_BUTTON(0, LeftBumper, ZeroGyroCommand);
ADD_BUTTON(0, LeftTrigger, WhileHeld, new ZeroElevatorCommand());
ADD_SIMPLE_BUTTON(0, Y, RaiseElevatorCommand);
ADD_SIMPLE_BUTTON(0, A, LowerElevatorCommand);
ADD_BUTTON(0, X, WhileHeld, new ButtonTinesCommand(1));
ADD_BUTTON(0, B, WhileHeld, new ButtonTinesCommand(-1));
