// Define Controllers as map with the form: Class, Port #
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 0)

// Define Axes in the form: Controller Port #, Axis Name, Logical Axis
ADD_AXIS(0, LeftY, logicalAxes::DriveY)
ADD_AXIS(0, LeftX, logicalAxes::DriveX)
ADD_AXIS(0, RightX, logicalAxes::DriveRotate)

//ADD_BUTTON(1, LeftJoystick, WhilePressed, new PreciseDriveCommand())
ADD_TOGGLE_BUTTON(0, X, PreciseDriveCommand)
ADD_SIMPLE_BUTTON(0, Back, ResetCommand)
ADD_BUTTON(0, Y, WhileHeld, new ButtonDriveCommand(0.3))
ADD_SIMPLE_BUTTON(0, B, ZeroGyroCommand)