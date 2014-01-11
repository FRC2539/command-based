#include "RunTalonCommand.h"

RunTalonCommand::RunTalonCommand(float speed) {
	Requires(talon);

	m_speed = speed;
}

// Called just before this Command runs the first time
void RunTalonCommand::Initialize() {
	talon->run(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void RunTalonCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool RunTalonCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RunTalonCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunTalonCommand::Interrupted() {
}
