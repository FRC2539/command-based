#include "ArcadeDriveCommand.h"

ArcadeDriveCommand::ArcadeDriveCommand() {
	Requires(drivetrain);
}

void ArcadeDriveCommand::Initialize() {
}

void ArcadeDriveCommand::Execute() {
	drivetrain->driveWithController(oi->getController());
}

bool ArcadeDriveCommand::IsFinished() {
	return false;
}

void ArcadeDriveCommand::End() {
}

void ArcadeDriveCommand::Interrupted() {
}
