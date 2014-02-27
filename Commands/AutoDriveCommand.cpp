#include "AutoDriveCommand.h"
#include <iostream>

AutoDriveCommand::AutoDriveCommand(float speed, float seconds) {
	Requires(drivetrain);
	m_speed = speed;
	m_seconds = seconds;
}

void AutoDriveCommand::Initialize() {
	drivetrain->move(m_speed, 0);
	SetTimeout(m_seconds);


	
	std::cout << "Being called";
	

}

void AutoDriveCommand::Execute() {
}

bool AutoDriveCommand::IsFinished() {
	return IsTimedOut();

}

void AutoDriveCommand::End() {
	drivetrain->move(0, 0);
}


void AutoDriveCommand::Interrupted() {
}

