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
ADD_TOGGLE_BUTTON(0, A, PreciseDriveCommand);
ADD_SIMPLE_BUTTON(0, B, ZeroGyroCommand);

/*
 * Pickup Controller
 */

ADD_SIMPLE_BUTTON(1, B, CloseTinesCommand);
ADD_BUTTON(1, X, WhenPressed, new SetTinesCommand(25));

ADD_BUTTON(1, LeftBumper, WhileHeld, new ButtonTinesCommand(1));
ADD_BUTTON(1, LeftTrigger, WhileHeld, new ButtonTinesCommand(-1));
ADD_BUTTON(1, Y, WhenPressed, new ChangeElevatorLevelCommand(1));
ADD_BUTTON(1, A, WhenPressed, new ChangeElevatorLevelCommand(-1));
ADD_BUTTON(1, RightBumper, WhileHeld, new ButtonElevatorCommand(Elevator::UP));
ADD_BUTTON(1, RightTrigger, WhileHeld, new ButtonElevatorCommand(Elevator::DOWN));

ADD_SIMPLE_BUTTON(1, Back, ResetCommand);
