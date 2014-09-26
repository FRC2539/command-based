// Define Controllers as map with the form: Port #, Class
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 1)

// Define Axes in the form: System Name, Controller Port #, Axis Name
ADD_AXIS(1, LeftY, logicalAxes::DriveY)
ADD_AXIS(1, RightX, logicalAxes::DriveRotate)

// Assign commands to buttons with the form:
//	   Controller Port #, Button Name, Event, Command
ADD_BUTTON(1, LeftJoystick, WhenPressed, new ToggleCommand(new PreciseArcadeDriveCommand()))
ADD_SIMPLE_BUTTON(1, Back, Reset)
ADD_SIMPLE_BUTTON(1, A, SafeBallPickUp)