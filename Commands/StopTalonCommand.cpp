#include "StopTalonCommand.h"

StopTalonCommand::StopTalonCommand() {
	Requires(talon);
}

// Called just before this Command runs the first time
void StopTalonCommand::Initialize() {
	talon->stop();
}

// Called repeatedly when this Command is scheduled to run
void StopTalonCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool StopTalonCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopTalonCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopTalonCommand::Interrupted() {
}
