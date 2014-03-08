#include "UnblockShooterCommand.h"

UnblockShooterCommand::UnblockShooterCommand() {
	std::cout << "UnblockShooterCommand Requires(pickup)\n";
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


