#ifndef DRIVEBASE_H
#define DRIVEBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class DriveBase: public Subsystem {
protected:
	Talon right;
	Talon left;
	
public:
	DriveBase();

	void InitDefaultCommand();

	void ArcadeDrive(float forward, float rotation);
	
	void stop();
};

#endif