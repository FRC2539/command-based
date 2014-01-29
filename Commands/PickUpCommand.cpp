#include "PickUpCommand.h"
#include "../Robotmap.h"

PickUpCommand::PickUpCommand() {
	Requires(pickup);
}

void PickUpCommand::Initialize() {
	controller = oi->getController();
}

void PickUpCommand::Execute() {
	pickup->pickup(
		controller->GetAxis(PICK_UP_AXIS)
	);
}

bool PickUpCommand::IsFinished() {
	return false;
}

void PickUpCommand::End() {
}

void PickUpCommand::Interrupted() {
}
