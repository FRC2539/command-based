#include "Tines.h"

#include <Talon.h>
#include <AnalogPotentiometer.h>

#include "../RobotMap.h"
#include "../Custom/Netconsole.h"

Tines::Tines() : Subsystem("Tines"), minPosition(0), maxPosition(0)
{
	tinesMotor = new Talon(RobotMap::Tines::tinesMotor);
	distanceDetector = new AnalogPotentiometer(RobotMap::Tines::stringPotentiometer);
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
