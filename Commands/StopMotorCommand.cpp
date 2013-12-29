#include "StopMotorCommand.h"

StopMotorCommand::StopMotorCommand() {
	Requires(motor);
}

// Called just before this Command runs the first time
void StopMotorCommand::Initialize() {
	motor->stop();
}

// Called repeatedly when this Command is scheduled to run
void StopMotorCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool StopMotorCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopMotorCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopMotorCommand::Interrupted() {
}
