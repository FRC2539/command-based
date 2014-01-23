#include "ArcadeDriveCommand.h"

ArcadeDriveCommand::ArcadeDriveCommand() {
	Requires(drivetrain);
}

void ArcadeDriveCommand::Initialize() {
	controller = oi->getController();
}

void ArcadeDriveCommand::Execute() {
	drivetrain->move(
		controller->GetAxis(controller->DRIVE_Y_AXIS),
		controller->GetAxis(controller->DRIVE_ROTATE_AXIS)
	);
}

bool ArcadeDriveCommand::IsFinished() {
	return false;
}

void ArcadeDriveCommand::End() {
}

void ArcadeDriveCommand::Interrupted() {
}
