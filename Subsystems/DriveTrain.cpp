#include "DriveTrain.h"

#include "../Custom/DriveTrain/EncoderDrive.h"
#include "../Commands/DriveCommand.h"

DriveTrain::DriveTrain(const char* type) : Subsystem(type)
{
}

DriveTrain::~DriveTrain()
{
	delete drive;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveCommand());
}

void DriveTrain::setMaxSpeed(float speed)
{
	drive->setMaxSpeed(speed);
}


