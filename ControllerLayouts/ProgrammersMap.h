// Define Controllers as map with the form: Port #, Class
// The currently available controller classes are:
// * LogitechAttack3Joystick
// * LogitechCrossfireController
// * LogitechDualShockController
ADD_CONTROLLER(LogitechDualShockController, 1)
ADD_CONTROLLER(LogitechDualShockController, 2)
// Define Axes in the form: System Name, Controller Port #, Axis Name
ADD_AXIS(1, LeftY, logicalAxes::DriveY)
ADD_AXIS(1, RightX, logicalAxes::DriveRotate)

// Assign commands to buttons with the form:
//	   Controller Port #, Button Name, Event, Command
//ADD_BUTTON(1, LeftJoystick, WhilePressed, new PreciseArcadeDriveCommand())
ADD_TOGGLE_BUTTON(1, LeftJoystick, PreciseArcadeDriveCommand)
ADD_SIMPLE_BUTTON(1, Back, ResetCommand)
ADD_SIMPLE_BUTTON(2, A, SafePickUpBallCommand)
ADD_SIMPLE_BUTTON(2, B, SafePassBallCommand) 
ADD_SIMPLE_BUTTON(2, RightTrigger, ToggleArmPositionCommand)