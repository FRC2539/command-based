#include "ButtonDriveCommand.h"

ButtonDriveCommand::ButtonDriveCommand(float speed)
	: DefaultCommand("ButtonDrive"), m_speed(speed)
{
	Requires(drivetrain);
}

void ButtonDriveCommand::Initialize()
{
	drivetrain->move(0, m_speed, 0);
}

void ButtonDriveCommand::End()
{
	drivetrain->stop();
}
