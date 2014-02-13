#include "RotateAngleCommand.h"

RotateAngleCommand::RotateAngleCommand(double timeout, float a) {
	Requires(drivetrain);
	SetTimeout(timeout);
	angle = a;
}	

void RotateAngleCommand::Initialize() {
	drivetrain->resetPID();
}

void RotateAngleCommand::Execute() {
	drivetrain->turnWithPID(angle);
}

bool RotateAngleCommand::IsFinished() {
	return IsTimedOut();
}

void RotateAngleCommand::End() {
}

void RotateAngleCommand::Interrupted() {
}
