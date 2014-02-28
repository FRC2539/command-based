#include "AutoDriveCommand.h"

AutoDriveCommand::AutoDriveCommand(float speed, float seconds) {
	std::cout << "AutoDriveCommand Requires(drivetrain)\n";
	Requires(drivetrain);
	m_speed = speed;
	m_seconds = seconds;
}

void AutoDriveCommand::Initialize() {
	drivetrain->move(m_speed, 0);
	SetTimeout(m_seconds);

	std::cout << "Initialized AutoDriveCommand\n";
}

void AutoDriveCommand::Execute() {
	drivetrain->move(m_speed, 0);
}

bool AutoDriveCommand::IsFinished() {
	return IsTimedOut();
}

void AutoDriveCommand::End() {
	drivetrain->move(0, 0);
	std::cout << "AutoDriveCommand Ended Normally\n";
}

void AutoDriveCommand::Interrupted() {
	std::cout << "AutoDriveCommand Interrupted!\n";
}

