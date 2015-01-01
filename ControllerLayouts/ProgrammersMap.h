// Define Controllers as map with the form: Class, Port #
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 1)

// Define Axes in the form: Controller Port #, Axis Name, Logical Axis
ADD_AXIS(1, LeftY, logicalAxes::DriveY)
ADD_AXIS(1, RightX, logicalAxes::DriveRotate)

//ADD_BUTTON(1, LeftJoystick, WhilePressed, new PreciseArcadeDriveCommand())
ADD_TOGGLE_BUTTON(1, LeftJoystick, PreciseArcadeDriveCommand)
ADD_SIMPLE_BUTTON(1, Back, ResetCommand)
