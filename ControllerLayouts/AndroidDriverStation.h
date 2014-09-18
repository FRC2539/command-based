ADD_CONTROLLER(AndroidDriverStation, 1)

ADD_AXIS(1, LeftY, DRIVE_AXIS_Y)
ADD_AXIS(1, LeftX, DRIVE_AXIS_ROTATE)

ADD_BUTTON(1, LeftSW, WhenPressed, new ToggleCommand(new PreciseArcadeDriveCommand()))
ADD_SIMPLE_BUTTON(1, RightSE, Reset)