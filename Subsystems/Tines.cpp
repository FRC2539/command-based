#include "Tines.h"

#include <Talon.h>
#include <AnalogPotentiometer.h>

#include "../RobotMap.h"
#include "../Custom/Netconsole.h"

Tines::Tines() : Subsystem("Tines"), minPosition(0), maxPosition(0)
{
	tinesMotor = new Talon(RobotMap::Tines::tinesMotorPort);
	// 0.794462=29 3/16, 0.306603=14 1/8
	// 0.487859 = 15.0625
	// Max = 30.874699
	// Min = 9.4662753
	distanceDetector = new AnalogPotentiometer(
		RobotMap::Tines::stringPotentiometerPort,
		21.408424,
		9.4662753
	);
}

Tines::~Tines()
{
	delete tinesMotor;
	delete distanceDetector;
}

void Tines::directDrive(float percentVoltage)
{
	tinesMotor->Set(percentVoltage);
	Netconsole::instant<float>("Position", distanceDetector->Get());
}

double Tines::getWidth()
{
	return distanceDetector->Get();
}

