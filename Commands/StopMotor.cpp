#include "StopMotor.h"

StopMotor::StopMotor() {
	Requires(motor);
}

// Called just before this Command runs the first time
void StopMotor::Initialize() {
	motor->stop();
}

// Called repeatedly when this Command is scheduled to run
void StopMotor::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool StopMotor::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopMotor::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopMotor::Interrupted() {
}
