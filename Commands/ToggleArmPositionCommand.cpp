#include "ToggleArmPositionCommand.h"

#include "../RobotMap.h" 

ToggleArmPositionCommand::ToggleArmPositionCommand() : TimedCommand("ToggleArmPosition", 500)
{

}

void ToggleArmPositionCommand::Initialize()
{
	if (pickuparm->getArmPosition() == DoubleSolenoid::kForward)
	{
		pickuparm->setArmPosition(DoubleSolenoid::kReverse);
	}
	else 
	{
		pickuparm->setArmPosition(DoubleSolenoid::kForward);
	}
}

void ToggleArmPositionCommand::End()
{
	pickuparm->setArmPosition(DoubleSolenoid::kOff);
}
