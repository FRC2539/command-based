#include "ArcadeDriveCommand.h"
#include "../ControllerMap.h"

ArcadeDriveCommand::ArcadeDriveCommand() {
	Requires(drivetrain);
}

void ArcadeDriveCommand::Initialize() {
}

void ArcadeDriveCommand::Execute() {
	drivetrain->move(
		oi->getAxis(DRIVE_Y_AXIS),
		oi->getAxis(DRIVE_ROTATE_AXIS)
	);
}

bool ArcadeDriveCommand::IsFinished() {
	return false;
}

void ArcadeDriveCommand::End() {
}

void ArcadeDriveCommand::Interrupted() {
}

