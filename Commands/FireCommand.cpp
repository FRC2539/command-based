#include "PreciseArcadeDriveCommand.h"
#include "../Robotmap.h"
#include <iostream>

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand() {
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Initialize() {
	wasReleased = false;
	controller = oi->getController();
}

void PreciseArcadeDriveCommand::Execute() {
	drivetrain->preciseMove(
		controller->GetAxis(DRIVE_Y_AXIS),
		controller->GetAxis(DRIVE_ROTATE_AXIS)
	);
}

bool PreciseArcadeDriveCommand::IsFinished() {
	if (justEnded)
	{
		justEnded = false;
		return true;
	}

	if (wasReleased && controller->GetButton(PRECISE_MOVEMENT_BUTTON))
	{
		justEnded = true;
		return true;
	}
	if ( ! controller->GetButton(PRECISE_MOVEMENT_BUTTON))
	{
		wasReleased = true;
	}

	return false;
}

void PreciseArcadeDriveCommand::End() {
}

void PreciseArcadeDriveCommand::Interrupted() {
}

bool PreciseArcadeDriveCommand::justEnded = false;
