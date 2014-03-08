#include "PickUpCommand.h"
#include "../ControllerMap.h"

PickUpCommand::PickUpCommand(float d) {
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
