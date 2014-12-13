#include "PickUpArm.h"

#include "../RobotMap.h"
#include <Victor.h>
#include <DigitalInput.h>
#include <DoubleSolenoid.h>

PickUpArm::PickUpArm() : Subsystem("PickUpArm")
{
	pickupWheelsMotor = new Victor(RobotMap::PickUpArm::wheelsMotorPort);
	ballSensor = new DigitalInput(RobotMap::PickUpArm::ballSensorPort);
	armPiston = new DoubleSolenoid(
		RobotMap::PickUpArm::lowerArmPort, 
		RobotMap::PickUpArm::RaiseArmPort
	);
	
	armPosition = DoubleSolenoid::kReverse; 
	
	DEBUG_SENSOR(ballSensor);
	DEBUG_MOTOR(pickupWheelsMotor);
	DEBUG_MOTOR(armPiston); 
}


PickUpArm::~PickUpArm()
{
	delete pickupWheelsMotor;
	delete ballSensor;
	delete armPiston;
}


void PickUpArm::setWheelSpeed(const float speed)
{
	pickupWheelsMotor->Set(speed);
}

void PickUpArm::setArmPosition(DoubleSolenoid::Value position)
{
	armPiston->Set(position);
	
	if (position != DoubleSolenoid::kOff)
	{
		armPosition = position;
	}
}

bool PickUpArm::hasBall()
{
	return ballSensor->Get();
}

DoubleSolenoid::Value PickUpArm::getArmPosition()
{
	return armPosition; 
}

