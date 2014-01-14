#include "DriveBase.h"
#include "../Robotmap.h"

DriveBase::DriveBase() : Subsystem("DriveBase"), right(RIGHT), left(LEFT) {
}


void DriveBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new ArcadeDrive());
}

void DriveBase::ArcadeDrive(float forward, float rotation){

	float r = 0;
	float l =0;

	r += forward;
	l -= forward;

	r -= rotation;
	l += rotation;

	right.Set(r);
	left.Set(l);


}


void DriveBase::stop() {
	right.Set(0);
	left.Set(0);
}
