#include "PickUpCommand.h"
#include "../ControllerMap.h"

PickUpCommand::PickUpCommand(float d) {
	std::cout << "PickUpCommand Requires(pickup)\n";
	Requires(pickup);

	direction = d;
}

void PickUpCommand::Initialize() {
}

void PickUpCommand::Execute() {
	pickup->pickup(direction);
}

bool PickUpCommand::IsFinished() {
	return false;
}

void PickUpCommand::End() {
	pickup->pickup(0);
}

void PickUpCommand::Interrupted() {
}
