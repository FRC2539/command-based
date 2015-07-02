#include "ButtonDriveCommand.h"

ButtonDriveCommand::ButtonDriveCommand(float x, float y, float rotate)
	: DefaultCommand("ButtonDrive"), m_x(x), m_y(y), m_rotate(rotate)
{
	Requires(drivetrain);
}

void ButtonDriveCommand::Initialize()
{
	drivetrain->move(m_x, m_y, m_rotate);
}

void ButtonDriveCommand::End()
{
	drivetrain->stop();
}
