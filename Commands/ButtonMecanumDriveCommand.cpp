#include "ButtonMecanumDriveCommand.h"

ButtonMecanumDriveCommand::ButtonMecanumDriveCommand(float x, float y, float rotate)
	: DefaultCommand("ButtonDrive"), m_x(x), m_y(y), m_rotate(rotate)
{
	Requires(drivetrain);
}

void ButtonMecanumDriveCommand::Initialize()
{
	drivetrain->move(m_x, m_y, m_rotate);
}

void ButtonMecanumDriveCommand::End()
{
	drivetrain->stop();
}
