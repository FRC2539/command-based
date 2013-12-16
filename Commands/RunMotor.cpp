#include "RunMotor.h"

RunMotor::RunMotor(float speed, double duration) {
	Requires(motor);

	m_speed = speed;
	m_timeout = duration;
}

// Called just before this Command runs the first time
void RunMotor::Initialize() {
	SetTimeout(m_timeout);
	motor->run(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void RunMotor::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool RunMotor::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void RunMotor::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunMotor::Interrupted() {
}
