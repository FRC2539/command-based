#include "DriveBase.h"
#include "../Robotmap.h"

DriveBase::DriveBase() : Subsystem("DriveBase"), frontRight(FRONT_RIGHT), frontLeft(FRONT_LEFT), backRight(BACK_RIGHT), backLeft(BACK_LEFT) {
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

	frontRight.Set(r);
	frontLeft.Set(l);
	backRight.Set(r);
	backLeft.Set(l);

}


void DriveBase::stop() {
	frontRight.Set(0);
	frontLeft.Set(0);
	backRight.Set(0);
	backLeft.Set(0);
}
