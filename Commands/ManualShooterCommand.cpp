#include "ManualShooterCommand.h"

ManualShooterCommand::ManualShooterCommand(double power)
	: DefaultCommand("ManualShooter"), m_power(power)
{
	Requires(shooter);
}

void ManualShooterCommand::Initialize()
{
	shooter->manualPivot(m_power);
}

void ManualShooterCommand::End()
{
	shooter->manualPivot(0);
}
