#include "AutoDriveCommand.h"

AutoDriveCommand::AutoDriveCommand(float speed, float seconds) {
	Requires(drivetrain);
	m_speed = speed;
	m_seconds = seconds;
}

void AutoDriveCommand::Initialize() {
	drivetrain->directDrive(m_speed, 0);
	SetTimeout(m_seconds);
}

void AutoDriveCommand::Execute() {
}

bool AutoDriveCommand::IsFinished() {
	return IsTimedOut();
}

void AutoDriveCommand::End() {
	drivetrain->directDrive(0, 0);
}

void AutoDriveCommand::Interrupted() {
}

