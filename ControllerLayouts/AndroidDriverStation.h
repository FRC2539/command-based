ADD_CONTROLLER(AndroidDriverStation, 1)

ADD_AXIS(1, LeftY, DriveAxisY)
ADD_AXIS(1, LeftX, DriveAxisRotate)

ADD_BUTTON(1, LeftSW, WhenPressed, new ToggleCommand(new PreciseArcadeDriveCommand()))
ADD_SIMPLE_BUTTON(1, RightSE, Reset)