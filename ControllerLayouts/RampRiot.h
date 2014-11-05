ADD_CONTROLLER(LogitechDualShockController, 1)
ADD_CONTROLLER(LogitechDualShockController, 2)

ADD_AXIS(1, LeftY, logicalAxes::DriveY)
ADD_AXIS(1, RightX, logicalAxes::DriveRotate)

ADD_TOGGLE_BUTTON(1, LeftJoystick, PreciseArcadeDriveCommand)
ADD_SIMPLE_BUTTON(1, Back, ResetCommand)
ADD_SIMPLE_BUTTON(2, A, SafePickUpBallCommand)
ADD_SIMPLE_BUTTON(2, B, SafePassBallCommand)
ADD_SIMPLE_BUTTON(2, RightTrigger, ToggleArmPositionCommand)