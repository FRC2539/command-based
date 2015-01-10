#include "DriveTimedCommand.h"

DriveTimedCommand::DriveTimedCommand(float speed, double seconds)
	: TimedCommand("DriveTimed", seconds)
{
	Requires(drivetrain);
	m_speed = speed;
}

void DriveTimedCommand::Initialize() {
	drivetrain->move(m_speed, 0);
}

void DriveTimedCommand::End() {
	drivetrain->move(0, 0);
}

