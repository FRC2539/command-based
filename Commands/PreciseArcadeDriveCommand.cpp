#include "PreciseArcadeDriveCommand.h"
#include "../ControllerMap.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand() {
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Initialize() {
	wasReleased = false;
}

void PreciseArcadeDriveCommand::Execute() {
	drivetrain->preciseMove(
		oi->getAxis(DRIVE_Y_AXIS),
		oi->getAxis(DRIVE_ROTATE_AXIS)
	);
}

bool PreciseArcadeDriveCommand::IsFinished() {
	if (justEnded)
	{
		justEnded = false;
		return true;
	}

	if (wasReleased && oi->getButton(PRECISE_MOVEMENT_BUTTON))
	{
		justEnded = true;
		return true;
	}
	if ( ! oi->getButton(PRECISE_MOVEMENT_BUTTON))
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