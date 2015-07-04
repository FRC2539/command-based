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
ADD_BUTTON(0, RightBumper, WhileHeld, new ButtonElevatorCommand(Elevator::UP));
ADD_BUTTON(0, RightTrigger, WhileHeld, new ButtonElevatorCommand(Elevator::DOWN));
ADD_SIMPLE_BUTTON(0, LeftBumper, ZeroGyroCommand);
ADD_BUTTON(0, Y, WhenPressed, new ChangeElevatorLevelCommand(1));
ADD_BUTTON(0, A, WhenPressed, new ChangeElevatorLevelCommand(-1));
ADD_BUTTON(0, X, WhileHeld, new ButtonTinesCommand(1));
ADD_BUTTON(0, B, WhileHeld, new ButtonTinesCommand(-1));
ADD_BUTTON(0, DPadUp, WhileHeld, new ButtonDriveCommand(0, .25));
ADD_BUTTON(0, DPadDown, WhileHeld, new ButtonDriveCommand(0, -.25));
ADD_BUTTON(0, DPadRight, WhileHeld, new ButtonDriveCommand(.25, 0));
ADD_BUTTON(0, DPadLeft, WhileHeld, new ButtonDriveCommand(-.25, 0));
