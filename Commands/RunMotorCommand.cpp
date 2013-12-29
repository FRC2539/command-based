#include "RunMotorCommand.h"

RunMotorCommand::RunMotorCommand(float speed) {
	Requires(motor);

	m_speed = speed;
}

// Called just before this Command runs the first time
void RunMotorCommand::Initialize() {
	motor->run(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void RunMotorCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool RunMotorCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RunMotorCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunMotorCommand::Interrupted() {
}
