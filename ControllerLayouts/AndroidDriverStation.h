ADD_CONTROLLER(AndroidDriverStation, 1)

ADD_AXIS(TwoAxisDrive, 1, LeftY)
ADD_AXIS(TwoAxisDrive, 1, RightX)

ADD_BUTTON(1, LeftSW, WhenPressed, new ToggleCommand(new PreciseArcadeDriveCommand()))
ADD_SIMPLE_BUTTON(1, RightSE, Reset)