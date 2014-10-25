#include "DriveTimedCommand.h"

DriveTimedCommand::DriveTimedCommand(float speed, double seconds)
	: TimedCommand("DriveTimed", seconds)
{
	Requires(drivetrain);
	m_speed = speed;
}

void DriveTimedCommand::Initialize() {
	drivetrain->directDrive(m_speed, 0);
}

void DriveTimedCommand::End() {
	drivetrain->directDrive(0, 0);
}

