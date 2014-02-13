#include "DriveDistanceCommand.h"

DriveDistanceCommand::DriveDistanceCommand(double timeout, float d) {
	Requires(drivetrain);
	SetTimeout(timeout);
	distance = d;
}	

void DriveDistanceCommand::Initialize() {
	drivetrain->resetPID();
}

void DriveDistanceCommand::Execute() {
	drivetrain->driveWithPID(distance);
}

bool DriveDistanceCommand::IsFinished() {
	return IsTimedOut();
}

void DriveDistanceCommand::End() {
}

void DriveDistanceCommand::Interrupted() {
}
