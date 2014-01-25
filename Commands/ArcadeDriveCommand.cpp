#include "ArcadeDriveCommand.h"
#include "../Robotmap.h"

ArcadeDriveCommand::ArcadeDriveCommand() {
	Requires(drivetrain);
}

void ArcadeDriveCommand::Initialize() {
	controller = oi->getController();
}

void ArcadeDriveCommand::Execute() {
	drivetrain->move(
		controller->GetAxis(DRIVE_Y_AXIS),
		controller->GetAxis(DRIVE_ROTATE_AXIS)
	);
}

bool ArcadeDriveCommand::IsFinished() {
	return false;
}

void ArcadeDriveCommand::End() {
}

void ArcadeDriveCommand::Interrupted() {
}
