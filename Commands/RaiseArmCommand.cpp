#include "RaiseArmCommand.h"

RaiseArmCommand::RaiseArmCommand() {
	Requires(pickup);
}

void RaiseArmCommand::Initialize() {
	pickup->raiseArm();
}

void RaiseArmCommand::Execute() {

}

bool RaiseArmCommand::IsFinished() {
	return true;
}

void RaiseArmCommand::End() {
}

void RaiseArmCommand::Interrupted() {
}

