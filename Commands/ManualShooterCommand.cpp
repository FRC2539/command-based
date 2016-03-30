#include "ManualShooterCommand.h"

ManualShooterCommand::ManualShooterCommand(float power)
	: DefaultCommand("manualRun"), voltage(power)
{
	Requires(shooter);
}

void ManualShooterCommand::Initialize()
{
	shooter->manualRun(voltage);
}

/*void ManualShooterCommand::Execute()
{
	elevator->updateDashboardHeight();
}*/

void ManualShooterCommand::End()
{
	shooter->manualRun(0);
}