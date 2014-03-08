#include "LowerArmCommand.h"

LowerArmCommand::LowerArmCommand() {
	Requires(pickup);
}

void LowerArmCommand::Initialize() {
	pickup->lowerArm();
}

void LowerArmCommand::Execute() {

}

bool LowerArmCommand::IsFinished() {
	return true;
}

void LowerArmCommand::End() {
}

void LowerArmCommand::Interrupted() {
}

