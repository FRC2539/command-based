#include "DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks() {
	Requires(drivebase);

}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
	forward = oi->GetControllerAxis(1);
	rotation = oi->GetControllerAxis(4);
	drivebase->ArcadeDrive(forward, rotation);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void DriveWithJoysticks::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {
}
