#include "PreciseArcadeDriveCommand.h"
#include "../Robotmap.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand() {
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Initialize() {
	controller = oi->getController();
}

void PreciseArcadeDriveCommand::Execute() {
	drivetrain->preciseMove(
		controller->GetAxis(DRIVE_Y_AXIS),
		controller->GetAxis(DRIVE_ROTATE_AXIS)
	);
}

bool PreciseArcadeDriveCommand::IsFinished() {
	return false;
}

void PreciseArcadeDriveCommand::End() {
}

void PreciseArcadeDriveCommand::Interrupted() {
}
