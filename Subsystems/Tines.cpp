#include "Tines.h"

#include <Talon.h>
#include <AnalogPotentiometer.h>

#include "../RobotMap.h"
#include "../Custom/Netconsole.h"

Tines::Tines() : Subsystem("Tines"), minPosition(0), maxPosition(0)
{
	tinesMotor = new Talon(RobotMap::Tines::tinesMotorPort);
	// Measurements: 0.794462=29 3/16", 0.306603=14 1/8"
	// Offset = 4.6587247
	// Max = 30.874699 + Offset
	distanceDetector = new AnalogPotentiometer(
		RobotMap::Tines::stringPotentiometerPort,
		30.874699,
		4.6587247
	);

	DEBUG_MOTOR(tinesMotor);
	DEBUG_SENSOR(distanceDetector);
}

Tines::~Tines()
{
	delete tinesMotor;
	delete distanceDetector;
}

void Tines::directDrive(float percentVoltage)
{
	tinesMotor->Set(percentVoltage);
	Netconsole::instant<float>("Width", distanceDetector->Get());
}

double Tines::getWidth()
{
	return distanceDetector->Get();
}

