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
ADD_TOGGLE_BUTTON(0, LeftJoystick, PreciseDriveCommand);
ADD_SIMPLE_BUTTON(0, Back, ResetCommand);
ADD_BUTTON(0, X, WhileHeld, new ButtonTinesCommand(1));
ADD_BUTTON(0, B, WhileHeld, new ButtonTinesCommand(-1));
ADD_BUTTON(0, DPadUp, WhileHeld, new ButtonDriveCommand(0, .25));
ADD_BUTTON(0, DPadDown, WhileHeld, new ButtonDriveCommand(0, -.25));
ADD_BUTTON(0, DPadRight, WhileHeld, new ButtonDriveCommand(.25, 0));
ADD_BUTTON(0, DPadLeft, WhileHeld, new ButtonDriveCommand(-.25, 0));
ADD_BUTTON(0, LeftTrigger, WhenPressed, new TineWidthCommand(25));
ADD_BUTTON(0, RightTrigger, WhenPressed, new TineWidthCommand(16));
ADD_BUTTON(0, A, WhenPressed, new TineWidthCommand(Config::Tines::maxWidth));
