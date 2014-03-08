#include "UnblockShooterCommand.h"

UnblockShooterCommand::UnblockShooterCommand() {
	Requires(pickup);
}

void UnblockShooterCommand::Initialize() {

}

void UnblockShooterCommand::Execute() {
}

bool UnblockShooterCommand::IsFinished() {
	return true;
}

void UnblockShooterCommand::End() {

}

void UnblockShooterCommand::Interrupted() {
}


