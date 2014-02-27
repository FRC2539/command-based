#include "ArcadeDriveCommand.h"
#include "../ControllerMap.h"

ArcadeDriveCommand::ArcadeDriveCommand() {
	std::cout << "ArcadeDriveCommand Requires(drivetrain)\n";
	Requires(drivetrain);
}

void ArcadeDriveCommand::Initialize() {
	std::cout << "ArcadeDriveCommand Initialized\n";
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
	std::cout << "ArcadeDriveCommand Ended Normally (Is that even possible?)\n";
}

void ArcadeDriveCommand::Interrupted() {
	std::cout << "ArcadeDriveCommand Interrupted\n";
}

