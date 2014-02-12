#include "PickUpCommand.h"
#include "../ControllerMap.h"

PickUpCommand::PickUpCommand() {
	Requires(pickup);
}

void PickUpCommand::Initialize() {
}

void PickUpCommand::Execute() {
	pickup->distancePickup(oi->getAxis(PICK_UP_AXIS));
}

bool PickUpCommand::IsFinished() {
	return false;
}

void PickUpCommand::End() {
}

void PickUpCommand::Interrupted() {
}
